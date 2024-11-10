#pragma once
#include"shape.h"
#include "point.h"
#include<iostream>

class rectangle: public shape{
    point A;
    point B;
    point C;
    point D;
public:
    rectangle(point a,point b,point c,point d,std::string& color1){
        A = a;
        B = b;
        C = c;
        D = d;
        color = color1;
    };
    float calculateSquare() const override{
        float h = pow((pow((B.y-A.y),2)+pow((A.x-B.x),2)),0.5);
        float ab = pow((pow((B.x-A.x),2)+pow((B.y-A.y),2)),0.5);
        float cd = pow((pow((D.x-C.x),2)+pow((D.y-C.y),2)),0.5);

        return (0.5*h*(ab+cd));
    }
    std::string getType() const override{
        return "Трапеция";
    }
    void printHeads() const override{
        printf("Вершины: A(%.2f,%.2f),B(%.2f,%.2f),C(%.2f,%.2f),D(%.2f,%.2f)\n",A.x,A.y,B.x,B.y,C.x,C.y,D.x,D.y);
    }
};