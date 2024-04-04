#include<iostream>
using namespace std;
int main(){
    int t,g,o,d;
    for(t=0;t<=9;t++){
        for(o=0;o<=9;o++){
            for(g=0;g<=9;g++){
                for(d=0;d<=9;d++){
                    if(4*(100*t+10*o+o)==1000*g+100*o+10*o+d){
                        if(t!=o&&t!=g&&t!=d){
                            if(o!=g&&o!=d&&g!=d){
                                cout<<"t"<<t<<"o"<<o<<"g"<<g<<"d"<<d<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
}
