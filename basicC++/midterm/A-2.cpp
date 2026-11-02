#include <iostream>
using namespace std;
int getValueByOption(int option)
{
    if (option != 1)
        return 250;
    else
        return 300;
}
int calculateProduct(int a, int b)
{
    return a * b;
}
int adjustValue(int value)
{
    if (value >= 1000)
        return value * 0.9;
    return value;
}
int calculateDifference(int a, int b)
{
    return a - b;
}
int main()
{
    string movieName;
    string ticketName;
    int ticketType;
    int quantity;
    int price;
    int subtotal;
    int total;
    int payment;
    int change;
    cout << "===== CINEMA TICKET KIOSK =====" << endl;
    cin >> movieName;
    cout << "1. Regular Ticket ($300)" << endl;
    cout << "2. Student Ticket ($250)" << endl;
    cin >> ticketType;
    cin >> quantity;
    cin >> payment;
    // TODO 1:
    // Use the functions from A-1 to calculate
    // price, subtotal, total, and change.
    price = getValueByOption(ticketType);
    subtotal = calculateProduct(price,quantity);
    total = adjustValue(subtotal);
    change = calculateDifference(payment,total);
    // TODO 2:
    // Set ticketName to "Regular" or "Student".
    if(ticketType == 1){
        ticketName = "Regular";
    }
    else if(ticketType == 2){
        ticketName = "Student";
    }
    
    cout << endl;
    cout << "===== RECEIPT =====" << endl;
    cout << "Movie: " << movieName << endl;
    cout << "Ticket Type: " << ticketName << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Total: $" << total << endl;
    cout << "Payment: $" << payment << endl;
    cout << "Change: $" << change << endl;
    return 0;
}