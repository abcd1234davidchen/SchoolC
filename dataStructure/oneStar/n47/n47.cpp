#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    char d[5] = "NWSE";
    char dir;
    int posx,posy,posdir=5;
    vector< pair<int,int> > vec;
    while(cin>>posx>>posy>>dir){
        if(dir=='N') posdir=0;
        else if(dir=='W') posdir=1;
        else if(dir=='S') posdir=2;
        else if(dir=='E') posdir=3;
        else continue;

        string ipt,buffer,fallMessage;
        getline(cin,buffer);
        getline(cin,ipt);
        fallMessage = "";

        for(size_t i=0;i<ipt.size();i++){
            if(ipt[i]=='R') posdir = (posdir+3)%4;
            else if(ipt[i]=='L') posdir = (posdir+1)%4;
            else if(ipt[i]=='F') {
                int ogX=posx,ogY=posy;
                if(posdir==0) posy+=1;
                else if(posdir==1) posx-=1;
                else if(posdir==2) posy-=1;
                else if(posdir==3) posx+=1;
                
                if(posx>x||posx<0||posy>y||posy<0){
                    bool flag = true;
                    for(size_t j=0;j<vec.size()&&flag;j++){
                        if(ogX==vec[j].first&&ogY==vec[j].second){
                            flag = false;
                        }
                    }
                    posx = ogX;
                    posy = ogY;
                    if(flag){
                        vec.push_back(make_pair(ogX,ogY));
                        fallMessage = " LOST";
                        break;
                    }
                }
            }            
        }
        cout<<posx<<" "<<posy<<" "<<d[posdir]<<fallMessage<<endl;
    }
}
