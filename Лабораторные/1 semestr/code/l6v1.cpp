#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*

    MUST BE INPUT.TXT, WHERE MUST BE WRITED NUMBER AND LETTERS
    THAT WE CHECK IN WORDS\TEXT
    
*/

int main(){
    //меняем кодировку на 1251
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");
/* 
        ЗАДАНИЕ 1
*/
    //вывод кириллицы
    for(int i = 0;i<16;i++){
        cout<<(char)(192+i)<<" = "<<192+i; //1 столбик
        cout<<"\t\t"<<(char)(192+i+16)<<" = "<<192+i+16; //2 столбик
        cout<<"\t\t"<<(char)(192+i+32)<<" = "<<192+i+32; //3 столбик
        cout<<"\t\t"<<(char)(192+i+48)<<" = "<<192+i+48<<endl; //4 столбик
    }
    cout<<(char)(168)<<" = 168\t\t"<<(char)(184)<<" = 184"<<endl; //вывод ё
    //вывод знаком препинания
    char znaks[]=".,:?-();!\"'"; //массив знаков препинания
    for(int i = 0;i<11;i++){ 
        cout<<znaks[i]<<" = "<<(int)znaks[i]<<endl; //вывод знак = номер
    }

    char arr[] = "еыаоэяиюу"; //массив изменяемых букв
    char str[] = "тестовая строка ё"; //изменяемая строка
    int i = 0;

    cout<<str<<" --> ";

    //меняем меняемые буквы
    while(str[i] != '\0'){
        bool fl = false; //флажок на нахождение изменяемой буквы
        int len = 0;  //номер символа в массиве изменяемых букв
        while(arr[len] != '\0'){
            if(arr[len] == str[i]) //если символ = изменяемая буква
                fl = true;
            len += 1; //номер символа строке изменяемых букв +1
        }
        //если символ = ё
        if(str[i]=='ё'){ 
            str[i] = (char)((int)str[i] - 16); //меняем на Ё
        }
        if(fl){ //если найден изменяемый символ
            str[i] = (char)((int)str[i] - 32);
        }
        i += 1; //номер символа в изменяемой строке +1
    }

    //вывод
    cout<<str<<endl;
/*
        ЗАДАНИЕ 2
*/
    int N ; // кол-во слов
    char check_ch; // буква

    //получение кол-во слов и буквы из инпута
    ifstream in("input.txt");
    //проверка наличия файла
    if(!in.is_open()){
        //если файла нет, то получаем с консоли
        cout<<"INPUT IS NOT FOUND"<<"ВВЕДИТЕ КОЛ-ВО И БУКВУ"<<endl;
        cout<<"N =";
        cin>>N;
        cout<<"буква: ";
        cin>>check_ch;
        check_ch = tolower(check_ch); //уменьшаем по высоте букву
        //если кол-во слов(N) абсурдно
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1; //выход
        }
    } else {
        //если файл присутствует, получаем данные
        in>>N;
        in>>check_ch;
        //уменьшаем по высоте
        check_ch = tolower(check_ch);
        //если кол-во слов абсурдно
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1; //выход
        }
        cout<<endl<<"N = "<<N<<endl;
        cout<<"буква = "<<check_ch<<endl;
        in.close(); //закрытие инпута
    }

    //получение текста
    ifstream txt("text.txt");
    //проверка наличия текста
    if(!txt.is_open()){ //если текста нет
        cout<<"ТЕКСТА НЕТ";
        return 1;
    } else { //если текст есть
        string words[10]; //массив слов
        string word; //слово
        string znaki(".,:?-();!\"'"); // + ... '' "" массив знаков
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
            //второй раз убираем троеточие(на случай, если вначале и в конце есть)
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
            if(word[size(word)-1] == check_ch){ //если последняя буква = нужная
                //сортировка пузырьком
                //----
                bool fl1 = true;
                while(fl1){
                    fl1 = false;
                    for(int a = 1;a<N;a++){
                        if(size(words[a]) > size(words[a-1])){
                            swap(words[a],words[a-1]);
                            fl1 = true;
                        }
                    } 
                }
                //----
                if(i < N){ //если есть место для нового слова
                    //проверяем его наличие
                    if(end(words) == find(begin(words),end(words),word)){
                        words[i] = word;
                        i++;
                    }
                } else { //если места нет
                    //сравниваем длины слов массива с новым
                    for(int j = 0;j<N;j++){
                        if(size(words[j]) < size(word))
                            if(end(words) == find(begin(words),end(words),word)){
                                words[j] = word;
                                break; //выход из сравнения
                        }
                    }
                }
            }
        }
        //открытие вывода
        ofstream out("result.txt");
        for(int i = 0;i<N;i++){
            //вывод в консоль и в файл
            cout<<words[i]<<" ";
            out<<words[i]<<" ";
        }
        out.close(); //закрытие вывода
    }
    txt.close(); //закрытие текста
    return 0;
}
