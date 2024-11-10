#pragma once
#include"shape.h"
#include "point.h"
#include<iostream>

class triangle: public shape{
    point A;
    point B;
    point C;
public:
    triangle(){};
    triangle(point a,point b,point c,std::string color1){
        A = a;
        B = b;
        C = c;
        color = color1;
    };
    float calculateSquare() const override{
        //https://otvet.mail.ru/question/53194356
        return abs(0.5*((A.x - C.x)*(B.y - C.y) - (B.x - C.x)*(A.y - C.y)));
    }
    std::string getType() const override{return "Треугольник";}
    void printHeads() const override{}
};