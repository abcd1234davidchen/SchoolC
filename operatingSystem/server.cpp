#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
using namespace std;

vector<int> clientSockets;

void message(const char* message,int senderSocket,int clientSocket = -1){
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
    cout<<"SOCKET"<<clientSocket<<endl;
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
            cout << "Received from: " << ntohs(clientAddress.sin_port) << buffer << endl;
            message(buffer,clientSocket);
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
    
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    
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