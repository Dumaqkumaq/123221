#include<iostream>
#include<algorithm>
/*
    Программа по определению палидромов
*/
int main(){
    std::string str;
    std::string str_after; //строка с символами до середины
    std::string str_after2; //строка с символами после середины

    //получаем строку
    std::cout<<"Write a string: ";
    std::cin>>str;

    //делим строку на две надвое(без серед элемента)
    str_after = str.substr(0,(int)(str.length()/2));
    str_after2 = str.substr((int)(str.length()/2)+1,str.length());

    //реверс второй части строки
    //странная фигня, но лень делать через цикл
    std::reverse(str_after2.begin(),str_after2.end());

    //сравниваем полученные строки для определения палидрома
    if (str_after == str_after2){
        std::cout<<"String is palindrom";

    } else {
        std::cout<<"String is not palindrom";

    }
}