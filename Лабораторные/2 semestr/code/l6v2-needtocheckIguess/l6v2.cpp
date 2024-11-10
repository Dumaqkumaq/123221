#include<iostream>
#include"triangle.h"
#include"rectangle.h"
#include"point.h"
#include <vector>

void FigureInfo(shape& figure){
    std::cout<<"Тип: "<<figure.getType()<<std::endl;
    std::cout<<"Цвет: "<<figure.getColor()<<std::endl;
    //std::cout<<"Вершины: "<<figure.printHeads()<<std::endl;
    figure.printHeads();
    std::cout<<"Площадь: "<<figure.calculateSquare()<<std::endl;
    std::cout<<std::endl;
}
int main(){
    system("chcp 1251");

    point a(1,4);
    point b(5,3);
    point c(0,3);
    point d(-3,5);
    std::string color = "blue";
    std::string color2 = "red";

    
    triangle tri(a,b,c,color);
    rectangle rec(a,b,c,d,color2);
    //переписать массив
    // std::vector<shape*> cases;
    // cases.push_back(&tri);
    // cases.push_back(&rec);
    
    // FigureInfo(*cases[0]);
    // FigureInfo(*cases[1]);

    // delete cases[0];
    // delete cases[1];


    return 0;
}