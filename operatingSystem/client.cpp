#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

using namespace std;

void* handleServer(void* arg){
    int clientSocket = *(int*)arg;
    delete (int*)arg;
    while(true){
        char buffer[1024] = {0};
        int bytesReceived = recv(clientSocket,buffer,sizeof(buffer),0);
        if (bytesReceived == 0||strcmp(buffer, "$ bye") == 0) {
            cout << "Server disconnected" << endl;
            break;
        }
        else if (bytesReceived > 0) {
            if(strcmp(buffer,"kill")==0){
                exit(0);
            }
            cout << "Server: " << buffer << endl; 
        }
        else{
            cerr << "recv failed" << endl;
            break;
        }
    }
    return nullptr;
}

int main()
{
    // creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // sending connection request
    int connectionStatus = connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    if (connectionStatus == -1) {
        cerr << "Connection to the server failed" << endl;
        close(clientSocket);
        return -1;
    }
    pthread_t thread;
    int* clientSocketPtr = new int(clientSocket);
    if (pthread_create(&thread, nullptr, handleServer, clientSocketPtr) != 0) {
        cerr << "Thread creation failed" << endl;
        delete clientSocketPtr;
        close(clientSocket);
        return -1;
    }
    
    while(true){
        string msg;
        cout << "Enter your message: ";
        getline(cin, msg);
        const char* message = msg.c_str();
        send(clientSocket, message, strlen(message), 0);
        if(msg=="$ bye"||msg=="kill") break;
    }
    
    close(clientSocket);

    return 0;
}
