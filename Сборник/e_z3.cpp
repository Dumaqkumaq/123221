#include<iostream>
/*
    Напишите программу, которая позволяет пользователю 
    ввести в консоль три координаты вектора x, y, и z, 
    с основанием у начала координат. 
    Вычислите длину этого вектора и выведите её обратно в консоль. 
*/
int main(){
    float x,y,z;
    double vector;

    // ввод координат
    std::cout<<"Write X: ";
    std::cin>>x;
    std::cout<<"Write Y: ";
    std::cin>>y;
    std::cout<<"Write Z: ";
    std::cin>>z;

    //вывод координат
    std::cout<<"You wrote these numbers: X = "<<x<<"; Y ="<<y<<"; Z = "<<z<<std::endl;

    // подсчет и вывод вектора
    vector = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    std::cout<<"Length of vector: "<<vector;
}