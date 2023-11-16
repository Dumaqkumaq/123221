#include<iostream>
#include<map>
using namespace std;
/* 
    ПЕРЕВОД РИМСКОГО ЧИСЛА В АРАБСКОЕ
 */
int main(){
    //Словарь для перевода римских символов в арабские
    map<char,int> romToInt{
        {'I',1},{'V',5},{'X',10},{'L',50},
        {'C',100},{'D',500},{'M',1000}
    };

    //short для экономии места
    short int answer = 0;
    string romanStr;
    short int i = 1;

    //получение строки римских чисел
    cout<<"Write ROM string to sransfer to INT: ";
    cin>>romanStr;

    //цикл разбора чисел
    while(i <= romanStr.size()){
        //обработка простых римских чисел -> I,V,X и так далее
        if(romToInt[romanStr[i-1]] >= romToInt[romanStr[i]]){
            answer += romToInt[romanStr[i-1]];
           // cout<<romToInt[romanStr[i-1]]<<endl; // для проверки
            i++;

        //обработка сложных римских чисел -> IV,IX и так далее
        } else{
            answer += romToInt[romanStr[i]] - romToInt[romanStr[i-1]];
            //cout<<romToInt[romanStr[i]] - romToInt[romanStr[i-1]]<<endl; // для проверки
            i+= 2;
            
        }
    }

    //вывод ответа
    cout<<answer;
}