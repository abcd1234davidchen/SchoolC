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

vector<int> clientSockets;
map<int,string> clients;
mutex wbMutex;

string getCurrentTime() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime); // Format: YYYY-MM-DD HH:MM:SS
    return string(buffer);
}

void message(const char* message,int senderSocket,int clientSocket = -1){

    sockaddr_in clientAddress;
    socklen_t clientAddrLen = sizeof(clientAddress);
    getpeername(senderSocket, (struct sockaddr*)&clientAddress, &clientAddrLen);

    ostringstream oss;
    oss << clients[senderSocket] <<": "<< message;
    string formattedMessage = oss.str();
    if(senderSocket!=0 && clientSocket!=-1){
        message = formattedMessage.c_str();
    }

    if (clientSocket==-1){
        for(int cs : clientSockets){
            if(cs!=senderSocket){
                send(cs,message,strlen(message),0);
            }
        }
    }
    else if(strcmp(message,"<Success>")==0){
        send(clientSocket,message,strlen(message),0);
        usleep(100000);
        for(int cs : clientSockets){
            if(cs!=clientSocket){
                sockaddr_in clientAddress;
                socklen_t clientAddrLen = sizeof(clientAddress);
                getpeername(cs, (struct sockaddr*)&clientAddress, &clientAddrLen);
                string msg = "<User " + clients[cs] + " is online, address: " 
                             + inet_ntoa(clientAddress.sin_addr) + "/" + to_string(ntohs(clientAddress.sin_port))+">";
                send(clientSocket,msg.c_str(),strlen(msg.c_str()),0);
                usleep(10000);
            }
        }
    }
    else{
        send(clientSocket,message,strlen(message),0);
    }
}

void* handleClient(void* arg) {
    int clientSocket = *(int*)arg;
    delete (int*)arg;

    sockaddr_in clientAddress;
    socklen_t clientAddrLen = sizeof(clientAddress);
    getpeername(clientSocket, (struct sockaddr*)&clientAddress, &clientAddrLen);

    clientSockets.push_back(clientSocket);

    while (true) {
        char buffer[1024] = {0};
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == 0||strcmp(buffer, "$ bye") == 0) {
            string msg = getCurrentTime()+" <User " + clients[clientSocket] + " disconnected>";
            {lock_guard<mutex> lock(wbMutex);
            cout<<msg<<endl;}
            message(msg.c_str(),clientSocket);
            break;
        }
        else if (bytesReceived > 0) {
            
            if(strncmp(buffer,"$ connect",9)==0){
                stringstream ss;
                ss<<buffer;
                string name;
                ss>>name>>name>>name>>name>>name;
                auto it = find_if(clients.begin(), clients.end(), 
                                  [&name](const pair<int, string>& client) {
                                      return client.second == name;
                                  });
                if (it != clients.end()) {
                    message("<User already exist>",0,clientSocket);
                    break;
                }
                else {
                    clients[clientSocket]=name;
                    {lock_guard<mutex> lock(wbMutex);
                    cout<<getCurrentTime()<<" <Client "<<name<<" on address: "<< inet_ntoa(clientAddress.sin_addr)<<"/"<<ntohs(clientAddress.sin_port)<<">"<<endl;}
                    message("<Success>",0,clientSocket);
                    stringstream ss;
                    ss << "<User " << name << " is online, address: " 
                       << inet_ntoa(clientAddress.sin_addr) << "/" << ntohs(clientAddress.sin_port)<<">";
                    string msg = ss.str();
                    message(msg.c_str(),clientSocket);
                }
            }
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
                cout<<getCurrentTime()<<" <"<<clients[clientSocket]<<" to "<<recipient<<"> Message: "<<msg<<endl;}
                auto it = find_if(clients.begin(), clients.end(), 
                                  [&recipient](const pair<int, string>& client) {
                                      return client.second == recipient;
                                  });
                if (it != clients.end()) {
                    int recipientSocket = it->first;
                    message(msg.c_str(), clientSocket, recipientSocket);
                }else {
                    string errorMsg = "<User "+recipient+" does not exist>";
                    message(errorMsg.c_str(),0,clientSocket);
                }
            }
        }
        else{
            cerr << "recv failed" << endl;
            break;
        }
    }
    close(clientSocket);
    clientSockets.erase(remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
    clients.erase(clientSocket);
    return nullptr;
}

int main() {
    clients[0]="Server";
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Socket creation failed" << endl;
        return 1;
    }

    int opt = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        cerr << "setsockopt(SO_REUSEADDR) failed" << endl;
        return 1;
    }
    string add;
    int port;
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    cout<<"Input <Address> <Port>"<<endl;
    cin>>add>>port;
    if (inet_pton(AF_INET, add.c_str(), &serverAddress.sin_addr) <= 0) {
        cerr << "Invalid address/ Address not supported" << endl;
    }
    if(::bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress))==-1){
        cerr<<"Bind failed" << endl;
        return 1;
    }
    
    cout << "IP: " << inet_ntoa(serverAddress.sin_addr) <<" Port: "<< ntohs(serverAddress.sin_port) << endl;
    
    if (listen(serverSocket, 5) < 0) {
        cerr << "Listen failed" << endl;
        return 1;
    }
        
    while (true) {
        sockaddr_in clientAddress;
        socklen_t clientAddrLen = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddrLen);
        
        if (clientSocket < 0) {
            cerr << "Accept failed" << endl;
            continue;
        }        
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
    close(serverSocket);
    return 0;
}