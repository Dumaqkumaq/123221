#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>
using namespace std;

class Circle{
    double radius_m = 0;
public:
//  CONSTRUCTORS
    Circle(){
        cout<<"!-----cannot create circle with zero radius"<<endl;
    }
    Circle(double radius){
//      checking given radius
        if((radius > 0) ?  true : false){
            radius_m = radius;
        } else {
            cout<<"!----- given radius is wrong"<<endl;
        }
    }
    Circle(Circle &circle){
        radius_m = circle.radius_m;
    }
//  FUNCTIONS AND METHODS

    void print(){
        cout<<"---INFO about circle:"<<endl;
        cout<<"-radius: "<<radius_m<<endl;
        cout<<"-length: "<<M_PI*2*radius_m<<endl;
    }
    double get_diametr(){
        return radius_m*2;
    }
    void calculate_length(){
        cout<<"length: "<<M_PI*2*radius_m<<endl;
    }
    double* get_radius_and_length(){
        double tmp[2] = {radius_m,M_PI*2*radius_m};
        return tmp;
    }
//  DECONSTRUCTOR
    ~Circle(){ cout<<"!----- circle deleted"<<endl;}
};
int main(){
    Circle a1;
    a1.print();
    double* ptr = a1.get_radius_and_length();
    cout<<ptr[0]<<" "<<ptr[1]<<endl;
    
    return 0;
}