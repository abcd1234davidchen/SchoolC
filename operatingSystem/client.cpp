#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sstream>

using namespace std;

void* handleServer(void* arg){
    int clientSocket = *(int*)arg;
    delete (int*)arg;
    while(true){
        char buffer[1024] = {0};
        int bytesReceived = recv(clientSocket,buffer,sizeof(buffer),0);
        if (bytesReceived == 0||strcmp(buffer, "$ bye") == 0) {
            cout << "Server disconnected" << endl;
            exit(0);
            break;
        }
        else if (bytesReceived > 0) {
            if(strcmp(buffer,"kill")==0){
                exit(0);
            }
            cout <<endl<< buffer<< endl; 
        }
        else{
            cerr << "Disconnect" << endl;
            break;
        }
    }
    return nullptr;
}

int main(){
    string login;
    string address;
    int port;
    string dump;
    getline(cin,login);
    while(true){
        while(true){
            if(strncmp(login.c_str(), "$ connect", 9) == 0){
                stringstream ss(login);
                ss>>dump>>dump>>address>>port>>dump;
                break;
            }
            else{
                cout<<"invalid input"<<endl;
                getline(cin,login);
                continue;
            }
        }
        while (true){
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
                getline(cin, login);
                break;
            } 
            else{
                cout<<"User "<<dump<<" login"<<endl;
            }
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
            send(clientSocket, login.c_str(), strlen(login.c_str()), 0);
            while(true){
                string msg;
                cout << "Enter your message: ";
                getline(cin, msg);
                const char* message = msg.c_str();
                send(clientSocket, message, strlen(message), 0);
                if(strncmp(msg.c_str(), "$ connect", 9) == 0){login=msg;break;}
                if(msg=="$ bye"){login="bye";break;}
            }
            close(clientSocket);
            if (login=="bye") {getline(cin,login);break;}
            if (strncmp(login.c_str(), "$ connect", 9) == 0) break;
        }
    }
    return 0;
}
