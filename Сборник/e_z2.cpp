#include<iostream>
#include<cmath>
/*
    Напишите программу , в которой по известной начальной скорости V 
    и времени полета тела T определяется угол aльфа под которым тело 
    брошено по отношению к горизонту 
    (воспользуйтесь соотношением a = arcsin(gT/2V)
*/
int main(){
    //получаем скорость и время
    float v,t;
    double pi = asin(1.0); // 
    std::cout<<"Write speed and time of flying\nV = ";
    std::cin>>v;
    std::cout<<"T = ";
    std::cin>>t;

    //считаем син через заданную формулу
    float alpha;
    alpha = ((9.8*t)/(2*v));

    //проверка синуса 
    if(abs(alpha) > 1){
        //если син не входит в диапазон [-1;1]
        std::cout<<"Not right info";
    } else{
        //получаем арксин
        alpha = asin(alpha);
        //переводим параметр в угол во время вывода
        std::cout<<"Angle => "<<alpha*(90/pi);
    }
}