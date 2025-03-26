#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sstream>

using namespace std;
bool loginStat = false;

void* handleServer(void* arg){
    int clientSocket = *(int*)arg;
    delete (int*)arg;
    while(true){
        char buffer[1024] = {0};
        int bytesReceived = recv(clientSocket,buffer,sizeof(buffer),0);
        if (bytesReceived == 0) {
            cout << "<Server disconnected>" << endl;
            break;
        }
        else if (bytesReceived > 0) {
            cout << buffer <<endl; 
            if(strcmp("<Success>",buffer)==0) loginStat = true;
        }
        else{
            cerr << "<Disconnect>" << endl;
            break;
        }
    }
    return nullptr;
}

int main(){
    string login;
    cout<<"Input: $ connect <address> <port> <name>"<<endl;
    getline(cin,login);
    while(true){
        string address;
        int port;
        string dump;
        string name;
        loginStat=false;
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
            else{
                cout<<"Invalid input"<<endl;
                cout<<"Input: $ connect <address> <port> <name>"<<endl;
                getline(cin,login);
                continue;
            }
        }
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
        int connectionStatus = connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
        if (connectionStatus == -1) {
            cerr << "Connection to the server failed" << endl;
            close(clientSocket);
            cout<<"Input: $ connect <address> <port> <name>"<<endl;
            getline(cin, login);
            continue;
        }
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
        //login = "$ connect "+address+ " "+to_string(port)+" "+name;
        send(clientSocket, login.c_str(), strlen(login.c_str()), 0);
        usleep(100000);
        while(loginStat){
            string msg;
            cout << "Enter your command: "<<endl;
            getline(cin, msg);
            const char* message = msg.c_str();
            if(strncmp(msg.c_str(), "$ connect", 9) == 0){login=msg;break;}
            send(clientSocket, message, strlen(message), 0);
            if(msg=="$ bye"){login="bye";break;}
        }
        close(clientSocket);
        if (login=="bye"||loginStat==false) {getline(cin,login);continue;}
        if (strncmp(login.c_str(), "$ connect", 9) == 0) continue;
    }
    return 0;
}
