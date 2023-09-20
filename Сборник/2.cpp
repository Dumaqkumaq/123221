#include<iostream>
/*
    Найти Y, если Y = X1 + X2 + … + Xn,   X = Z^3 - B + A^2 / tg^2?. 
    Количество X вводятся пользователем программы. 
    Для каждого X значения Z, B, А разные 
    (вводятся пользователем программы).
*/
int main(){
    float y = 0;
    float z,b,a,betta;

    //получаем кол-во икс
    int kolvo_x;
    std::cout<<"Write number of X: ";
    std::cin>>kolvo_x;

    //получаем Z,B,A,Betta для подсчета икс
    for(int i=0;i!=kolvo_x;i++){
        std::cout<<"\nWrite Z, B, A, Betta for X"<<i+1;
        std::cout<<"\nZ = ";
        std::cin>>z;
        std::cout<<"B = ";
        std::cin>>b;
        std::cout<<"A = ";
        std::cin>>a;
        std::cout<<"Betta = ";
        std::cin>>betta;
        //сразу считаем знач икс и прибавляем его к Y
        y += pow(z,3) - b + (pow(a,2) / pow(tan(betta),2));
    }
    
    //вывод итогового значения
    std::cout<<"\ny = "<<y;
}