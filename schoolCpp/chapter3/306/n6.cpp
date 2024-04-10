#include<iostream>
#include<cmath>

using namespace std;

double average(double s1,double s2,double s3,double s4){
    return (s1+s2+s3+s4)/4;
}
double s(double score,double average){
    return (score-average)*(score-average);
}
double stDe(double s1,double s2,double s3,double s4){
    double avg=average(s1,s2,s3,s4);
    return sqrt(average(s(s1,avg),s(s2,avg),s(s3,avg),s(s4,avg)));
}

int main(){
    double s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    cout<<stDe(s1,s2,s3,s4);
}
