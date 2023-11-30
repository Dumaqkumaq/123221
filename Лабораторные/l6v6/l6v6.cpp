#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");
    int N ; // кол-во слов мин длины
    
    //получение кол-во слов и букв из инпута
    ifstream in("input.txt");
    //проверка наличия файла
    if(!in.is_open()){
        //если файла нет, то получаем с консоли
        cout<<"НЕТ ИНПУТА"<<"ВВЕДИТЕ КОЛ-ВО В КОНСОЛЬ"<<endl;
        cout<<"N =";
        cin>>N;
        //если кол-во слов абсурдно
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1;
        }
    } else {
        //если файл присутствует, получаем данные
        in>>N;
        //если кол-во слов абсурдно
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1;
        }
        //вывод для проверки
        cout<<endl<<"N = "<<N<<endl;
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
        int num_arr[10]; // массив длин слов
        /*
            Небольшое пояснение идеи(без учета сортировки):
            words -> массив именно слов
            num_arr -> массив КОЛ-ВО ГЛАСНЫХ

            Например: words = {мама, дом, зуба, лупапупа}
            индекс слова "мама" равен 0 и кол-во гласных равно 2, тогда
            ячейка с номером 0 в num_arr равна 2
            тогда -> num_arr = {2}
            такой алгоритм со всеми словами
            после всех действий получаем: num_arr = {2, 1, 2, 4}

            соответственно, длина массива с кол-во гласных равна 10, т.к. слов всего может быть 10
        */
        string word; //слово из текста
        string znaki(".,:?-();!\"'"); // + ... '' "" строка символов
        string chk("уеыаоэяию"); // массив проверяемых букв
        int i = 0; //номер слова в массиве слов

        while(!txt.eof()){
            int len = 0;// номер символа в слове
            int count = 0;// кол-во гласных в текущем слове
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
            //считаем кол-во гласных
            while(word[len] != '\0'){
                if(chk.find(word[len]) != string::npos) // ищем гласную в слове
                    count += 1; // +1, если нашли одну гласную
                len++; // переходим на новый символ слова
            }
            //работаем с массивом
            if(i < N){ //если место еще есть
                if(end(words) == find(begin(words),end(words),word)){ //ищем такое же слово в массиве
                    //если его нет, то добавляем:
                    words[i] = word; // <-- в массив слов
                    num_arr[i] = count; // <-- в массив кол-во глассных
                    i++;
                }
            } else { //если места уже нет
                //сортировка пузырьком
                //----
                bool fl1 = true;
                while(fl1){
                    fl1 = false;
                    for(int a = 1;a<N;a++){
                        if(num_arr[a] < num_arr[a-1]){
                            swap(words[a],words[a-1]);
                            swap(num_arr[a],num_arr[a-1]);
                            fl1 = true;
                        }
                    } 
                }
                //----
                //сравниваем кол-во гласных слов в массиве с кол-во в текущем слове
                for(int b = 0;b<N;b++){ // проходимся по словам
                    if(count>num_arr[b]){ // сравниваем текущее кол-во с кол-во слова под индексом b
                        if(end(words) == find(begin(words),end(words),word)){ // смотрим его наличие в масииве
                                //если такого слова нет, то:
                                words[b] = word; // <-- меняем слова в массиве
                                num_arr[b] = count; // <-- меняем кол-во глассных в другом массиве
                                break;
                        }
                    }
                }
            }
        }
        //сортировка в порядке убывания перед выводом
        bool fl1 = true;
        while(fl1){
            fl1 = false;
            for(int a = 1;a<N;a++){
                if(num_arr[a] > num_arr[a-1]){
                    swap(words[a],words[a-1]);
                    swap(num_arr[a],num_arr[a-1]);
                    fl1 = true;
                }
            } 
        }
        //открытие вывода
        ofstream out("result.txt");
        for(int g = 0;g<N;g++){
            //вывод в файл и в консоль для отслеживания результата
            cout<<words[g]<<" --> "<<num_arr[g]<<endl;
            out<<words[g]<<" --> "<<num_arr[g]<<endl;
        }
        out.close();
    }
    txt.close();
    
    return 0;
}
