#include<iostream>
/*
    Написать программу, которая получает радиус круга. 
    Посчи-тать длину окружности. 
*/
int main(){
    //инициализация типов данных и их размеры
    char ch; // -128 - 126
    unsigned char un_ch; // 0 - 255
    short sh; // -32768 - 32767
    unsigned short un_sh; // 0 - 65536
    long lng; // -2.147.483.648 - 2.147.483.648
    unsigned long un_lng; // 0 - 4.294.967.295
    int in; // -2.147.483.648 - 2.147.483.648
    unsigned int un_in; // 0 - 4.294.967.295
    float flo; // -3,4*10**(-38) - 3,4*10**(-38)
    double doubl; // -3,4*10**(-4932) - 3,4*10**(4932)
    bool bo; // true или false

    float radius;
    float pi = 3.14;
    // используем double на случай, если пользователь
    // введет макс значение float
    double ploshad;

    std::cout<<"Radius: ";
    std::cin>>radius;
    ploshad = pi*2*radius;
    std::cout<<"Ploshad -> "<<ploshad;

}