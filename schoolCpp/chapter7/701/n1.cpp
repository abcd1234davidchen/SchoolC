#include<iostream>
using namespace std;

const char colors[8][10]={"Red","Orange","Yellow","Green","Blue","Violet","Purple","None"};

class RainbowColor{
    private:
        int color;
    public:
        RainbowColor():color(7){}
        RainbowColor(int x):color(x%7){}
        RainbowColor(char a):color(7){
            for(int i=0;i<7;i++){
                if(a==colors[i][0]){
                    color=i;
                }
            }
        }
        void inputColor(int x){
            color=x;
        }
        int outColorCode(){
            return color;
        }
        string outColorName(){
            return colors[color];
        }
        RainbowColor nextColor(){
            return RainbowColor((color+1)%7);
        }
};
int main(){
    RainbowColor color1('R');
    RainbowColor color2;
    RainbowColor color3(6);
    RainbowColor color4=color3.nextColor();
    cout<<color1.outColorName()<<color2.outColorName()<<color3.outColorName()<<color4.outColorName();
}
