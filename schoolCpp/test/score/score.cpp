#include <iostream>
#include <string>
using namespace std;

double score(const string& s){
    if (s =="A+" || s == "a+") {
        return 4.3;
    }
    else if (s=="A" || s=="a"){
        return 4.0;
    }
    else if (s=="A-" || s=="a-"){
        return 3.7;
    }
    else if (s=="B+" || s=="b+"){
        return 3.3;
    }
    else if (s=="B" || s=="b"){
        return 3.0;
    }
    else if (s=="B-" || s=="b-"){
        return 2.7;
    }
    else if (s=="C+" || s=="c+"){
        return 2.3;
    }
    else if (s=="C" || s=="c"){
        return 2.0;
    }
    else if (s=="C-" || s=="c-"){
        return 1.7;
    }
    else if (s=="D+" || s=="d+"){
        return 1.3;
    }
    else if (s=="D" || s=="d"){
        return 1.0;
    }
    else if (s=="D-" || s=="d-"){
        return 0.7;
    }
    else if (s=="F" || s=="f"){
        return 0.0;
    }
    else{
        return -1;
    }
}
int main(){
    string s;
    int credits;
    string creditinput;
    double total_score=0;
    int total_credits=0;
    do{
        cout<<"Enter the number of credits: ";
        cin>>creditinput;
        if (creditinput=="q" || creditinput=="Q"){
            cout<<"Your GPA is: "<<total_score/total_credits<<endl;
            break;
        }
        else{
            credits=stoi(creditinput);
        }

        cout<<"Enter a letter grade: ";
        cin>>s;

        if (score(s)==-1){
            cout<<"Invalid letter grade."<<endl;
            continue;
        }
        else{
            total_score+=score(s)*credits;
            total_credits+=credits;
        }
    }while(1);
}
