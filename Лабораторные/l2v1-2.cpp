#include <iostream>
/*
    Установить значение i-го бита числа в 1.
*/
int main(){
    unsigned int x = 7;
    //x = 98;
    //x = 241;
    // 7 = 00000111
//unsigned char X = 98; 
// 98 = 01100010
//unsigned char X = 241; 
// 241 = 11110001

    int i;
    //получаем номер изменяемого бита
    std::cout<<"i = ";
    std::cin>>i;

    std::cout<<x<<" ==> ";
    //изменяем i бит числа х
    x |= (1<<(i-1));
    std::cout<<x;

    //один доп
    std::cout<<"\n-----DOPbI-----\n";
    //выводим изначальное х и инвертированное х
    std::cout<<x<<" ==> "<<(~x);

}
