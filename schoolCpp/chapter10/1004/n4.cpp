#include<iostream>
#include<vector>
using namespace std;
class subscriber{
    private:
        string name;
        int numChannels;
        string* channellist;
    public:
        subscriber(string n, int num){
            name = n;
        }
        ~subscriber(){
            delete[] channellist;
        }
        void input(){
            cout << "Enter name: ";
            cin >> name;
            string channel;
            cout << "Enter channel list (end with 'done'): ";
            vector<string> tempChannellist;
            while(cin >> channel && channel != "done"){
                tempChannellist.push_back(channel);
            }
            numChannels = tempChannellist.size();
            channellist = new string[numChannels];
            for(int i = 0; i < numChannels; i++){
                channellist[i] = tempChannellist[i];
            }
        }
        void display(){
            cout << "Name: " << name << endl;
            cout << "Number of channels: " << numChannels << endl;
            cout << "Channel list: ";
            for(int i=0; i<numChannels; i++){
                cout << channellist[i] << " ";
            }
            cout << endl;
        }
        void reset(){
            delete[] channellist;
            numChannels = 0;
        }
        void addChannel(string channel){
            string* temp = new string[numChannels+1];
            for(int i=0; i<numChannels; i++){
                temp[i] = channellist[i];
            }
            temp[numChannels] = channel;
            numChannels++;
            delete[] channellist;
            channellist = temp;
        }
};