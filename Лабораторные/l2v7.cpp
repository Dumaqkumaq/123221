#include<iostream>
/* 
    Узнать значение i-го бита числа,
    используя сдвиг, но без маски.
 */
int main(){
    unsigned int x = 98;
// 7 = 00000111
// 3 = 00000011
// 4 = 00000100
// 8 = 00001000

    int i; //i - номер искомого бита
    std::cout<<"i = ";
    std::cin>>i;
    
    x = x >> (i-1); // сдвигаем i-бит в начало
    x = x << 31; // сдвигаем влево, пока не останется i-бит
    x = x >> 31; // сдвигаем i-бит в начало
    
    //вывод значение i-бита
    std::cout<<"x = "<<x;
}
