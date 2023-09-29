#include<iostream>
/*
    Написать программу, которая получает на вход 
    значение площади треугольника и его высоты. 
    Рассчитать значение основания.
*/
int main(){
    //инициализация типов данных и их размеры
    
    short sh = 123; // -32768 - 32767
    unsigned short un_sh = 123; // 0 - 65536
    long lng = 123; // -2.147.483.648 - 2.147.483.648
    unsigned long un_lng = 123; // 0 - 4.294.967.295
    long long lng_lng = 123;
    int in = 53; // -2.147.483.648 - 2.147.483.648
    unsigned int un_in = 543; // 0 - 4.294.967.295
    float flo = 5748; // -3,4*10**(-38) - 3,4*10**(-38)
    double doubl = 134; // -3,4*10**(-4932) - 3,4*10**(4932)

    //используем float из-за возможного ввода дробных чисел
    float square, height;
    //используем double из-за возможного использования макс знач float
    double base;

    std::cout<<"Write square of triangle: ";
    std::cin>>square;
    std::cout<<"Write height of triangle: ";
    std::cin>>height;

    base = 2*square/height;

    std::cout<<"\nBase of triangle => "<<base;
}
