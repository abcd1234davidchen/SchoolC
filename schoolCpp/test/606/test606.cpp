#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

volatile sig_atomic_t flag = 0;

void my_function(int sig){ // can be called asynchronously
  flag = 1; // set flag
}

class gasPump {
private:
    double dispense; // 已經分配的燃料量
    double charge; // 已經收取的費用
    double pricePerGallon; // 每單位燃料的費用

public:
    gasPump() : dispense(0), charge(0), pricePerGallon(2.5) {} // 假設每單位燃料的費用為2.5

    void add(){
        signal(SIGINT, my_function);
        while(1){
            if(flag){
                cout << "Interrupt signal received.\n";
                break;
            }
            dispense++;
            charge=dispense*pricePerGallon;
            cout << "\r\033[K" << "Dispense: " << dispense << ", Charge: " << charge << flush;
            usleep(50*1000); // sleep for 1 second
        }
    }
    void out(){
        cout << "Dispense: " << dispense << ", Charge: " << charge << "\n";
    }
};

int main() {
    gasPump gas;
    gas.add();
    gas.out();
    return 0;
}