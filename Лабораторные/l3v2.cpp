#include<iostream>
using namespace std;
/*
    1.	Если A+B кратно C и C кратно B, 
    то вывести (A+B)/C-C/B, если A+B кратно C и C не кратно B, то вывести (A+B)/С+B*C, 
    в остальных случаях вывести A-B+C

    2.	Ввести натуральное число N, 
    обозначающее номер месяца в году. Вывести название месяца.

    ДОП. Переменная X может принимать 2 значения: -1 и 1. 
    Если -1, то вывести в кон-соль “Negative number”, 
    если положительное - “Positive number”.
*/
int main(){
    /*
        Задание 1
    */
    int a,b,c; // целые числа

    //ввод A,B,C
    cout<<"A = ";
    cin>>a;

    cout<<"B = ";
    cin>>b;

    cout<<"C = ";
    cin>>c;

    //рассматриваем условия
    if((a>0)&&(b>0)&&(c>0)){ // проверяем натуральность чисел
        if (((a+b)%c==0)&&((c%b)==0)){
            cout<<"(A+B)/C-C/B, "<<(a+b)/c-c/b<<endl;

        } else if (((a+b)%c==0)&&((c%b)!=0)) {
            cout<<"(A+B)/C+B*C, "<<(a+b)/c+b*c<<endl;

        } else {
            cout<<"A-B+C, "<<a-b+c<<endl; 

        }
    } else {
        cout<<"Not natural numbers"<<endl;
        
    }

    /*
        Задание 2
    */
    int n; // номер месяца в году
    
    //ввод n
    cout<<"\nN = ";
    cin>>n;

    //Вывод месяца по номеру n
    switch(n){
        case 1:cout<<"January"; break;
        case 2:cout<<"February"; break;
        case 3:cout<<"March"; break;
        case 4:cout<<"April"; break;
        case 5:cout<<"May"; break;
        case 6:cout<<"June"; break;
        case 7:cout<<"July"; break;
        case 8:cout<<"August"; break;
        case 9:cout<<"September"; break;
        case 10:cout<<"October"; break;
        case 11:cout<<"November"; break;
        case 12:cout<<"December"; break;
        default:cout<<"Wrong number"; break;
    }

    /*
        Доп
    */
    int x;

    //ввод x
    cout<<"\n\nX MAY BE 1 OR -1\nX = ";
    cin>>x;

    //Вывод ответа, зависящего от х
    (x == 1) ? cout<<"Positive number":cout<<"Negative number";
}