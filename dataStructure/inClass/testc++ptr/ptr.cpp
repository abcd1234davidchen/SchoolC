#include<iostream>

int addOne(int *ptr){
    *ptr = *ptr + 1;
    return *ptr;
}
int main(){
    int a=10;
    std::cout << "a = " << a << std::endl;
    std::cout << "addOne(a) = " << addOne(&a) << std::endl;
    std::cout << "a = " << a << std::endl;
}