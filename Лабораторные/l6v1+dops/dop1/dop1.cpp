#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    //использование кириллицы
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");
    //открытие инпута
    ifstream in("cod.txt");
    if(!in.is_open()){
        cout<<"cod.txt is not found"<<endl;
        return 1;
    } else {
        string answer(""); //строка с ответом
        string word; //строка получаемого слова
        string arr_of_nums("1234567890"); //строка цифр
        while(!in.eof()){
            in>>word;
            //если первый символ слова = цифре
            if(arr_of_nums.find(word[0]) != string::npos){
                //начинаем декодировать слова
                int i = 1; //для цикла по проходке по полученному слову(случай, когда число = 146374 и более)
                string num(""); //строка цифр числа
                //получаем цифры
                while(word[i] != '\0'){
                    num += word[i-1];
                    i++;
                }
                //умножаем число на нужную букву + пробел
                answer+=string (stoi(num),word[size(word)-1]) + " ";
            //если нужно закодировать
            } else {
                int len = 0; //кол-во символов
                while(word[len] != '\0'){
                    len++; //подсчет кол-во
                }
                //переводим число в строку и приписываем к букве + пробел
                answer+=to_string(len) +word[0] + " ";
            }
        }
        in.close(); //закрытие кода
        ofstream out("cod.txt"); //открытие вывода
        cout<<answer<<endl; //вывод в консоль для проверки
        out<<answer; //вывод в файл
        out.close(); //закрытие вывода
    }
    return 0;
}