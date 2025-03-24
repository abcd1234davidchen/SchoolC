#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sstream>
#include <map>
using namespace std;

vector<int> clientSockets;
map<int,string> clients;

void message(const char* message,int senderSocket,int clientSocket = -1){

    sockaddr_in clientAddress;
    socklen_t clientAddrLen = sizeof(clientAddress);
    getpeername(senderSocket, (struct sockaddr*)&clientAddress, &clientAddrLen);

    ostringstream oss;
    oss << "Client: "<< clients[senderSocket] << message;
    string formattedMessage = oss.str();
    if(strcmp(message,"kill")!=0){
        message = formattedMessage.c_str();
    }

    if (clientSocket==-1){
        for(int cs : clientSockets){
            if(cs!=senderSocket){
                send(cs,message,strlen(message),0);
            }
        }
    }
    else{
        send(clientSocket,message,strlen(message),0);
    }
    if(strcmp(message,"kill")==0) exit(0);
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
            cout << "Client on port " << ntohs(clientAddress.sin_port) << " disconnected" << endl;
            break;
        }
        else if (bytesReceived > 0) {
            
            if(strncmp(buffer,"$ connect",9)==0){
                stringstream ss;
                ss<<buffer;
                string name;
                ss>>name>>name>>name>>name>>name;
                clients[clientSocket]=name;
                cout<<"Client "<<name<<" on address: "<< inet_ntoa(clientAddress.sin_addr)<<"/"<<ntohs(clientAddress.sin_port)<<endl;
            }
            else{
                cout << "Received from " << ntohs(clientAddress.sin_port) << ": "<< buffer << endl;
                message(buffer,clientSocket);
            }
            
        }
        else{
            cerr << "recv failed" << endl;
            break;
        }
    }
    close(clientSocket);
    clientSockets.erase(remove(clientSockets.begin(), clientSockets.end(), clientSocket), clientSockets.end());
    return nullptr;
}

int main() {
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
    
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0) {
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
        
        cout << "Client connected: " << inet_ntoa(clientAddress.sin_addr)<<" Port: "<<ntohs(clientAddress.sin_port) << endl;
        
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