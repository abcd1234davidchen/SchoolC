#include<iostream>
using namespace std;

bool isLeapYear(int year){
    if(year%400==0||(year%4==0&&year%100!=0)){
        cout<<"LEAP TRUE"<<endl;
        return true;
    }
    else{
        cout<<"LEAP FALSE"<<endl;
        return false;
    } 
}

int getCenturyValue(int year){
    int result=(3-((year/100)%4))*2;
    cout<<"CENTURY"<<result<<endl;
    return result;
}

int getYearValue(int year){
    int result=(year%100)+((year%100)/4);
    cout<<"YEAR"<<result<<endl;
    return result;
}

int getMonthValue(int year,int month){
    int value=0;
    switch (month)
    {
    case 1:
        if(isLeapYear(year)) value=6;
        else value=0;
        break;
    case 2:
        if(isLeapYear(year)) value=2;
        else value=3;
        break;
    case 3:
        value=3;
        break;
    case 4:
        value=6;
        break;
    case 5:
        value=1;
        break;
    case 6:
        value=4;
        break;
    case 7:
        value=6;
        break;
    case 8:
        value=2;
        break;
    case 9:
        value=5;
        break;
    case 10:
        value=0;
        break;
    case 11:
        value=3;
        break;
    case 12:
        value=5;
        break;
    
    default:
        break;
    }
    cout<<"MONTH"<<value<<endl;
    return value;
}

int main(){
    int year,month,day,dayOfWeek;
    cin>>year>>month>>day;
    dayOfWeek=day+getMonthValue(year,month)+getYearValue(year)+getCenturyValue(year);
    dayOfWeek%=7;
    switch(dayOfWeek){
        case 1:
            cout<<"Monday"<<endl;
            break;
        case 2:
            cout<<"Tuesday"<<endl;
            break;
        case 3:
            cout<<"Wednesday"<<endl;
            break;
        case 4:
            cout<<"Thursday"<<endl;
            break;
        case 5:
            cout<<"Friday"<<endl;
            break;
        case 6:
            cout<<"Saturday"<<endl;
            break;
        case 0:
            cout<<"Sunday"<<endl;
            break;
    }
    cout<<dayOfWeek<<endl;
}
