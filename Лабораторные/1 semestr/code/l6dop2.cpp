#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*

    MUST BE INPUT.TXT, WHERE MUST BE WRITED NUMBER AND LETTERS
    THAT WE CHECK IN WORDS\TEXT
    
*/
int main(){
    //использование кириллицы
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");

    int N ; // кол-во слов мин длины
    char check_ch; // искомая буква
    string iskl; //исключение
    //получение кол-во слов и букв из инпута
    ifstream in("input.txt");
    //проверка наличия файла
    if(!in.is_open()){
        //если файла нет, то получаем из консоли
        cout<<"INPUT IS NOT FOUND"<<"ВВЕДИТЕ КОЛ-ВО И БУКВу В КОНСОЛЬ"<<endl;
        cout<<"N =";
        cin>>N;
        cout<<"буква: ";
        cin>>check_ch;
        cout<<"исключение: ";
        cin>>iskl;
        check_ch = tolower(check_ch); //уменьшаем по высоте исключение
        for(int j = 0;j<size(iskl);j++){
            iskl[j] = tolower(iskl[j]);
        }
        //если кол-во слов (N) абсурдно
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1; //выход
        }
    } else {
        //если файл присутствует, получаем данные
        in>>N;
        in>>check_ch;
        in>>iskl;
        //переводим полученные буквы в строчные
        check_ch = tolower(check_ch);
        for(int j = 0;j<size(iskl);j++){
            iskl[j] = tolower(iskl[j]);
        }
        //вывод для проверки
        cout<<endl<<"N = "<<N<<endl;
        cout<<"Проверяемая буква = "<<check_ch<<endl;
        cout<<"исключение = "<<iskl<<endl;
        in.close(); //закрываем инпут
    }

    //получение текста
    ifstream txt("text.txt");
    //проверка наличия текста
    if(!txt.is_open()){ //если текста нет
        cout<<"ТЕКСТА НЕТ";
        return 1;
    } else { //если получилось открыть текст
        string words[10]; //массив слов
        string word; //слово из текста
        string znaki(".,:?-();!\"'"); // + ... '' "" строка символов
        int i = 0; //номер слова в массиве слов
        
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
            //избавляемся от троеточия x2
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            //избавляемся от знака препинания в начале
            if(znaki.find(word[0]) != string::npos){
                word.erase(0,1);
            }
            //избавляемся от знака препинания в конце
            if(znaki.find(word[size(word)-1]) != string::npos){
                word.erase(size(word)-1,1);
            }
            //обработка подходящего слова
            if(word[size(word)-1] == check_ch || word == iskl){ //если последняя бува = искомой или слово = исключ
                if(word == iskl && word[size(word)-1] == check_ch) //если слово = исключ и последняя бува = искомой
                    continue; //пропуск обработки
                //сортировка пузырьком (чтобы сразу отсортировать по длине)
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
                if(i < N){ //если есть место для новых слов
                    //если слова нет в массиве, то добавляем его в массив
                    if(end(words) == find(begin(words),end(words),word)){
                        words[i] = word;
                        i++;
                    }
                } else { //достигли предела по кол-во слов
                    //проходимся по словам для сравнения длин
                    for(int j = 0;j<N;j++){
                        if(size(words[j]) < size(word))
                            //проверяем наличие слова в массиве
                            if(end(words) == find(begin(words),end(words),word)){
                                words[j] = word;
                                break; //выход из цикла
                        }
                    }
                }
            }
        }
        //открытие вывода
        ofstream out("result.txt");
        for(int i = 0;i<N;i++){
            //вывод в файл и в консоль для отслеживания результата
            cout<<words[i]<<" ";
            out<<words[i]<<" ";
        }
        out.close(); //закрытие вывода
    }
    txt.close(); //закрытие текста
    return 0;
}
