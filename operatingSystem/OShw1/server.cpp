#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sstream>
#include <map>
#include <mutex>
#include <ctime>
using namespace std;

vector<int> clientSockets;  //list of existing client
map<int,string> clients;    //client name
vector<string> offline;     //offline user
mutex wbMutex;              //whiteboard mutex
string whiteboard;          //whiteboard

//Make string that contains current time
string getCurrentTime() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    string rt = "["+string(buffer)+"]";
    return rt;
}

//Send message user
void message(const char* msg,int senderSocket,int clientSocket = -1){
    sockaddr_in clientAddress;
    socklen_t clientAddrLen = sizeof(clientAddress);
    getpeername(senderSocket, (struct sockaddr*)&clientAddress, &clientAddrLen);

    //form message to contain sender
    ostringstream oss;
    oss << clients[senderSocket] <<": "<< msg;
    string formattedMessage = oss.str();
    //Don't modify if the message is made by server or the message is online message
    if(senderSocket!=0 && clientSocket!=-1){
        msg = formattedMessage.c_str();
    }

    //Broadcast message to everyone except the sender itself
    if (clientSocket==-1){
        for(int cs : clientSockets){
            if(cs!=senderSocket){
                send(cs,msg,strlen(msg),0);
            }
        }
        if(strcmp(msg,"<Kill>")==0){
            system("clear");
            exit(0);
        }
    }
    //Send success message and all existing user
    else if(strcmp(msg,"<Success>")==0){
        send(clientSocket,msg,strlen(msg),0);
        usleep(100000);
        //list of existing user except itself
        for(int cs : clientSockets){
            if(cs!=clientSocket){
                sockaddr_in clientAddress;
                socklen_t clientAddrLen = sizeof(clientAddress);
                getpeername(cs, (struct sockaddr*)&clientAddress, &clientAddrLen);
                string msg = "<User " + clients[cs] + " is on-line, socket address: " 
                                + string(inet_ntoa(clientAddress.sin_addr))
                                + "/" + to_string(ntohs(clientAddress.sin_port))+">";
                send(clientSocket,msg.c_str(),strlen(msg.c_str()),0);
                usleep(10000);
            }
        }
    }
    //send message from one to another
    else{
        send(clientSocket,msg,strlen(msg),0);
    }
}

//Handle client through socket
void* handleClient(void* arg) {
    int clientSocket = *(int*)arg;
    delete (int*)arg;

    //get client info through socket
    sockaddr_in clientAddress;
    socklen_t clientAddrLen = sizeof(clientAddress);
    getpeername(clientSocket, (struct sockaddr*)&clientAddress, &clientAddrLen);
    
    //add user to list
    clientSockets.push_back(clientSocket);

    //while connecting keep receiving message and process
    while (true) {
        char buffer[1024] = {0};
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);

        //if disconnected or bye is sent write whiteboard broacast and stop receving message
        if (bytesReceived == 0||strcmp(buffer, "$ bye") == 0) {
            string msg ="<User " + clients[clientSocket] + " is off-line>";
            string wbmsg="<Client " + clients[clientSocket] + " disconnected>";
            {lock_guard<mutex> lock(wbMutex);
            whiteboard+=(getCurrentTime()+" "+wbmsg+"\n");
            system("clear");
            cout<<whiteboard;}
            message(msg.c_str(),clientSocket);
            break;
        }

        //if receive other message
        else if (bytesReceived > 0) {
            //case of connect message
            if(strncmp(buffer,"$ connect",9)==0){
                stringstream ss;
                ss<<buffer;
                string name;
                ss>>name>>name>>name>>name>>name;
                auto it = find_if(clients.begin(), clients.end(), 
                                  [&name](const pair<int, string>& client) {
                                      return client.second == name;
                                  });

                //if the name already exist end connection
                if (it != clients.end()) {
                    message("<User already exist>",0,clientSocket);
                    break;
                }
                //else store name and broadcast about new user
                else {
                    clients[clientSocket]=name;
                    {lock_guard<mutex> lock(wbMutex);
                    string wbmsg = getCurrentTime() + " <Client " + name
                                   + " on address: " + inet_ntoa(clientAddress.sin_addr)
                                   + "/" + to_string(ntohs(clientAddress.sin_port)) + ">\n";
                    whiteboard+=wbmsg;
                    system("clear");
                    cout<<whiteboard;}
                    message("<Success>",0,clientSocket);
                    stringstream ss;
                    ss << "<User " << name << " is on-line, address: " 
                       << inet_ntoa(clientAddress.sin_addr)
                       << "/" << ntohs(clientAddress.sin_port)<<">";
                    string msg = ss.str();
                    message(msg.c_str(),clientSocket);
                }
            }
            //case of chat other user
            else if(strncmp(buffer, "$ chat", 6) == 0) {
                stringstream ss(buffer);
                string command, recipient, msg;
                ss >> command >> command >> recipient;
                getline(ss, msg);
                if (!msg.empty() && msg[0] == ' ') {
                    msg.erase(0, 1);
                }
                if (!msg.empty() && msg[0] == '"' && msg[msg.size() - 1] == '"') {
                    msg = msg.substr(1, msg.size() - 2);
                }
                {lock_guard<mutex> lock(wbMutex);
                string wbmsg = getCurrentTime() +" "+ clients[clientSocket] + " is using the whiteboard.\n<To "
                              +recipient+"> "+msg+"\n";
                whiteboard+=wbmsg;
                system("clear");
                cout << whiteboard;}
                auto it = find_if(clients.begin(), clients.end(), 
                                  [&recipient](const pair<int, string>& client) {
                                      return client.second == recipient;
                                  });
                //check if the recipient exist
                if (it != clients.end()) {
                    int recipientSocket = it->first;
                    message(msg.c_str(), clientSocket, recipientSocket);
                }
                //check if recipient is offline
                else if (find(offline.begin(), offline.end(), recipient) != offline.end()) {
                    string offlineMsg = "<User " + recipient + " is off-line>";
                    message(offlineMsg.c_str(), 0, clientSocket);
                }
                //throw error if not
                else {
                    string errorMsg = "<User "+recipient+" does not exist>";
                    message(errorMsg.c_str(),0,clientSocket);
                }
            }
            //case of kill message
            else if(strcmp(buffer,"kill")==0){
                message("<Kill>",0);
            }
        }

        //other cases
        else{
            cerr << "recv failed" << endl;
            break;
        }
    }
    //after disconnect close socket and erase existence
    offline.push_back(clients[clientSocket]);
    close(clientSocket);
    clientSockets.erase(remove(clientSockets.begin()
                        ,clientSockets.end(),clientSocket),clientSockets.end());
    clients.erase(clientSocket);
    return nullptr;
}

int main() {
    //set user 0 to server
    clients[0]="Server";

    //create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Socket creation failed" << endl;
        return 1;
    }
    
    //make the port reusable
    int opt = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        cerr << "setsockopt(SO_REUSEADDR) failed" << endl;
        return 1;
    }

    //bind socket with given address and port
    string add;
    int port=8080;
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    cout<<"Input <Address> <Port>"<<endl;
    cin>>add>>port;
    if (inet_pton(AF_INET, add.c_str(), &serverAddress.sin_addr) <= 0) {
        cerr << "Invalid address/ Address not supported" << endl;
    }
    if(::bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress))==-1){
        cerr<<"Bind failed" << endl;
        return 1;
    }

    //write init message to whiteboard
    {lock_guard<mutex> lock(wbMutex);
    string wbmsg = " <IP: " + string(inet_ntoa(serverAddress.sin_addr)) 
                   + " Port: " + to_string(ntohs(serverAddress.sin_port)) + ">\n";
    whiteboard+=wbmsg;
    system("clear");
    cout<<whiteboard;}
    
    //allow user to connect
    if (listen(serverSocket, 5) < 0) {
        cerr << "Listen failed" << endl;
        return 1;
    }
    
    //case of connection formed
    while (true) {
        sockaddr_in clientAddress;
        socklen_t clientAddrLen = sizeof(clientAddress);
        int clientSocket=accept(serverSocket,
                                (struct sockaddr*)&clientAddress, &clientAddrLen);
        
        //if user connection failed
        if (clientSocket < 0) {
            cerr << "Accept failed" << endl;
            continue;
        }

        //create thread to hold connection
        pthread_t thread;
        int* clientSocketPtr = new int(clientSocket);
        if (pthread_create(&thread, nullptr, handleClient, clientSocketPtr) != 0) {
            cerr << "Thread creation failed" << endl;
            delete clientSocketPtr;
            close(clientSocket);
            continue;
        }
        pthread_detach(thread);
    }
    //shut down socket
    close(serverSocket);
    return 0;
}