#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sstream>
using namespace std;

bool loginStat = false; //login status

//Handle message from server
void* handleServer(void* arg){
    int clientSocket = *(int*)arg;
    delete (int*)arg;
    while(true){
        char buffer[1024] = {0};
        int bytesReceived = recv(clientSocket,buffer,sizeof(buffer),0);

        //disconencted
        if (bytesReceived == 0) {
            cout << "<Server disconnected>" << endl;
            break;
        }

        //receive message
        else if (bytesReceived > 0) {
            cout << buffer <<endl; 
            if(strcmp("<Success>",buffer)==0) loginStat = true;
            if(strcmp("<Kill>",buffer)==0) {system("clear");exit(0);}
        }

        //other
        else{
            cerr << "<Disconnect>" << endl;
            break;
        }
    }
    return nullptr;
}

int main(){
    //form connection
    string login;
    cout<<"Input: $ connect <address> <port> <name>"<<endl;
    getline(cin,login);
    while(true){
        string address;
        int port;
        string dump;
        string name;
        loginStat=false;
        //loop until login message is correct
        while(true){
            if(strncmp(login.c_str(), "$ connect", 9) == 0){
                stringstream ss(login);
                ss>>dump>>dump>>address>>port>>name;
                if(name.empty()){
                    cout<<"Invalid input"<<endl;
                    cout<<"Input: $ connect <address> <port> <name>"<<endl;
                    getline(cin,login);
                    continue;
                }
                break;
            }
            else if(strncmp(login.c_str(), "kill", 9) == 0){system("clear");exit(0);}
            else{
                cout<<"Invalid input"<<endl;
                cout<<"Input: $ connect <address> <port> <name>"<<endl;
                getline(cin,login);
                continue;
            }
        }

        //create socket for connection
        int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket == -1) {
            cerr << "Socket creation failed" << endl;
            return -1;
        }
        sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(port);
        if (inet_pton(AF_INET, address.c_str(), &serverAddress.sin_addr) <= 0) {
            cerr << "Invalid address/ Address not supported" << endl;
            close(clientSocket);
            cout<<"Input: $ connect <address> <port> <name>"<<endl;
            getline(cin, login);
            continue;
        }
        int connectionStatus = connect(clientSocket,
                (struct sockaddr*)&serverAddress, sizeof(serverAddress));
        if (connectionStatus == -1) {
            cerr << "Connection to the server failed" << endl;
            close(clientSocket);
            cout<<"Input: $ connect <address> <port> <name>"<<endl;
            getline(cin, login);
            continue;
        }

        //create thread to hold connection
        pthread_t thread;
        int* clientSocketPtr = new int(clientSocket);
        if (pthread_create(&thread, nullptr, handleServer, clientSocketPtr) != 0) {
            cerr << "Thread creation failed" << endl;
            delete clientSocketPtr;
            close(clientSocket);
            cout<<"Input: $ connect <address> <port> <name>"<<endl;
            getline(cin, login);
            continue;
        }
        
        //send login message for server to process
        send(clientSocket, login.c_str(), strlen(login.c_str()), 0);
        usleep(100000);
        //check if login
        while(loginStat){
            string msg;
            cout << "Enter your command: "<<endl;
            getline(cin, msg);
            const char* message = msg.c_str();
            if(strncmp(msg.c_str(), "$ connect", 9) == 0){login=msg;break;}
            send(clientSocket, message, strlen(message), 0);
            if(msg=="$ bye"){login="bye";break;}
        }
        //when disconnected
        close(clientSocket);
        //case of bye
        if (login=="bye"||loginStat==false) {getline(cin,login);continue;}
        usleep(100000);
        //case of connect message again
        if (strncmp(login.c_str(), "$ connect", 9) == 0) continue;
    }
    return 0;
}
