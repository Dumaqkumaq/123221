#include<iostream>
/*
1. Дана последовательность целых чисел {A1, A2, …, AN}.
Найти произведение всех чисел, оканчивающихся на 3,
наименьшее из таких чисел и его номер в последовательности.
2. Дано целое число X <10^9. Найти сумму цифр числа.
*/
int main(){
    /*
    Задание 1
    */

    //получение кол-во последовательности
    int amount_of_number;
    std::cout<<"Write an amount of numbers: ";
    std::cin>>amount_of_number;

    //проверка полученного кол-во последовательности
    if (amount_of_number < 0) {
        std::cout<<"Amount can not be below zero";
        return 1;
    }

    //получение последовательности
    int number;
    int multiply = 1;
    int min_number = 2147483647;
    int min_i;
    bool fl = 0;

    //сущ наборы данных при которых не прав
    if(amount_of_number == 0){
        multiply = 0;
    } else {
        std::cout<<"Write numbers\n";
    }

    for(int i = 0;i != amount_of_number;i++){
        //получение числа
        std::cout<<i+1<<" => ";
        std::cin>>number;

        //проверка числа
        if (number % 10 == 3){
            multiply *= number;
            fl = 1;
            //нахождение мин и его номер
            if(number < min_number) {
                min_number = number;
                min_i = i+1;
            }
        }
    }

    //используем флаг для обозначения нахождения подходящего числа
    if(fl){
        std::cout<<"Multiply = "<<multiply<<"\nMinimum number = "<<min_number<<"\nPlace of min number = "<<min_i;
    } else {
        multiply = 0;
        std::cout<<"Multiply = 0";
    }

    /*
    Задание 2
    */

    int x;
    std::cout<<"\n\nWrite a X: ";
    std::cin>>x;

    //проверка X
    if(x >= (1000000000)){
        std::cout<<"X is too big";
        return 1;
    }

    //считаем сумму цифр числа Х
    int summary = 0;
    x = std::abs(x);
    while(x > 0){
        summary += x%10;
        x = (int)(x/10);
    }

    //вывод
    std::cout<<"Summary = "<<summary;
}