#include<iostream>
using namespace std;

class Vector2D{
    private:
        int x;
        int y;
    public:
        Vector2D(int a,int b): x(a),y(b){}
        Vector2D(int a): x(a),y(0){}
        Vector2D():x(0),y(0){}
        friend istream& operator>>(istream& is,Vector2D& vec){
            is>>vec.x>>vec.y;
            return is;
        }
        friend ostream& operator<<(ostream& os,const Vector2D& vec){
            os<<vec.x<<","<<vec.y;
            return os;
        }
        friend double operator*(const Vector2D vec1,const Vector2D vec2){
            return vec1.x*vec2.x+vec1.y*vec2.y;
        }
};

int main(){
    Vector2D a,b;
    cin>>a>>b;
    cout<<a*b;
}
