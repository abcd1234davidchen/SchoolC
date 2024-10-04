#include<iostream> 
using namespace std; 
 
int main() { 
    int Money; 
    int Fifty=0, Twenty=0, Ten=0, Five=0, One=0; 
    cout << "Enter a EUR amount: "; 
    cin >> Money; 

    while (Money >= 50){ 
        Money -=50; 
        Fifty ++; 
    } 
    while (Money >= 20){ 
        Money -= 20; 
        Twenty ++; 
    } 
    while (Money >= 10){ 
        Money -= 10; 
        Ten ++; 
    } 
    while (Money >= 5){ 
        Money -= 5; 
        Five++; 
    } 
    while (Money >= 1){ 
        Money -= 1; 
        One++; 
    } 

    cout << "The input corresponds to" << endl; 
    cout << "$50 bills: " << Fifty << endl; 
    cout << "$20 bills: " << Twenty << endl; 
    cout << "$10 bills: " << Ten << endl; 
    cout << " $5 bills: " << Five << endl; 
    cout << " $1 coins: " << One << endl; 

    return 0; 
}
