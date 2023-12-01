#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
//удаление знака 
//
//

int main(){
    //использование кириллицы
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");
/* 
        задание 1
*/
    //вывод кириллицы
    for(int i = 0;i<16;i++){
        cout<<(char)(192+i)<<" = "<<192+i;
        cout<<"\t\t"<<(char)(192+i+16)<<" = "<<192+i+16;
        cout<<"\t\t"<<(char)(192+i+32)<<" = "<<192+i+32;
        cout<<"\t\t"<<(char)(192+i+48)<<" = "<<192+i+48<<endl;
    }
    cout<<(char)(168)<<" = 168\t\t"<<(char)(184)<<" = 184"<<endl;

    char arr[] = "цкнгшщзхфвпрлджчсмтб"; //строка лишних символов
    char str[100] = "Это Тестовая Строка"; //изменяемая строка
    char str_tmp[100] = ""; //строка-ответ
    int i = 0; //номер элемента изменяемой строки
    int i_tmp = 0; //номер элекмента строки-ответа
    //если изменяемая строка пустая(случай ввода с консоли)
    if(str[0]=='\0'){
        cout<<"Введите строку: ";
        cin>>str;
    }
    cout<<str<<" --> "; //вывод изменяемой строки

    //идем по строке для нахождения согл
    while(str[i] != '\0'){
        //проверка символа на согл
        bool fl = false;
/* 
*         принцип идеи:
*               берем элемент изменяемой строки 
*               и проверяем его на наличие в "лишних символах"
*               если это ложь, то записываем символ в строку-ответ
*               если правда, то пропускаем элемент
*/
        int len = 0;
        while(arr[len] != '\0'){
            char simvB = tolower(str[i]); //уменьшаем высоту символа(А -> а)
            if(arr[len] == simvB) //если данный символ является согл
                fl = true; //флаг = правда
            len += 1;
        }
        if(!fl){ //если данный элемент не согл
            str_tmp[i_tmp] = str[i]; //записываем данный элемент в строку-ответ
            i_tmp++; //переходим на след элемент в строке-ответ
        }
        i += 1; //переходим на след символ в изменяемой строке
    }
    //вывод ответа
    cout<<str_tmp<<endl;
/* 
        задание 2
*/
 /*    int N ; // кол-во слов мин длины
    string check_ch; // массив проверяемых букв
    
    //получение кол-во слов и букв из инпута
    ifstream in("input.txt");
    //проверка наличия файла
    if(!in.is_open()){
        //если файла нет, то получаем с консоли
        cout<<"INPUT IS NOT FOUND"<<"ВВЕДИТЕ КОЛ-ВО И БУКВЫ В КОНСОЛЬ"<<endl;
        cout<<"N =";
        cin>>N;
        cout<<"буквы: ";
        cin>>check_ch;
        //если кол-во слов абсурдно
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1;
        }
    } else {
        //если файл присутствует, получаем данные
        in>>N;
        in>>check_ch;
        //переводим полученные буквы в строчные
        int j = 0;
        while(check_ch[j] != '\0'){

        }
        //вывод для проверки
        cout<<endl<<"N = "<<N<<endl;
        cout<<"Проверяемые буквы = "<<check_ch<<endl;
        in.close();
    }

    //получение текста
    ifstream txt("text.txt");
    //проверка наличия текста
    if(!txt.is_open()){
        cout<<"ТЕКСТА НЕТ";
        return 1;
    } else {
        string words[10]; //массив слов
        string word; //слово из текста
        string znaki(".,:?-();!\"'"); // + ... '' "" строка символов
        i = 0; //номер слова в массиве слов

        while(!txt.eof()){
            txt>>word;
            //уменьшаем слово по высоте
            for(int j = 0;j<size(word);j++){
                word[j] = tolower(word[j]);
            }
            //избавляемся от троеточия
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            //на всяк случай
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            //избавляемся от знаков препинания в начале
            if(znaki.find(word[0]) != string::npos){
                word.erase(0,1);
            }
            //избавляемся от знаков препинания в конце
            if(znaki.find(word[size(word)-1]) != string::npos){
                word.erase(size(word)-1,1);
            }
            //обработка подходящего слова
            if(word.find(check_ch[0]) != string::npos && word.find(check_ch[1]) != string::npos){
                //сортировка массива слов
                //метод сорт криво работал, поэтому использую пузырьки
                bool fl1 = true;
                while(fl1){
                    fl1 = false;
                    for(int a = 0;a<N;a++){
                        if(size(words[a]) < size(words[a+1])){
                            swap(words[a],words[a+1]);
                            fl1 = true;
                        }
                    } 
                }
                //если не достигли предела по кол-во слов
                if(i < N){
                    //если слова нет в массиве
                    if(end(words) == find(begin(words),end(words),word)){
                        words[i] = word;
                        i++;
                    }
                //достигли предела по кол-во слов
                } else {
                    //проходимся по словам для сравнения длин
                    for(int j = 0;j<N;j++){
                        if(size(words[j]) > size(word))
                            //проверяем наличие слова в массиве
                            if(end(words) == find(begin(words),end(words),word)){
                                words[j] = word;
                                break;
                        }
                    }
                }
            }
        }
        //конечная сортировка (тут уже норм работает)
        sort(begin(words),words+i); 
        //открытие вывода
        ofstream out("result.txt");
        for(int i = 0;i<N;i++){
            //вывод в файл и в консоль для отслеживания результата
            cout<<words[i]<<" ";
            out<<words[i]<<" ";
        }
        out.close();
    }
    txt.close();
     */
    return 0;
}