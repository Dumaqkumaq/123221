#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
/*

    MUST BE INPUT.TXT, WHERE MUST BE WRITED NUMBER AND LETTERS
    THAT WE CHECK IN WORDS\TEXT
    
*/

int main(){
    //using russian
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");
/* 
        task 1
*/
    //output russian
    for(int i = 0;i<16;i++){
        cout<<(char)(192+i)<<" = "<<192+i;
        cout<<"\t\t"<<(char)(192+i+16)<<" = "<<192+i+16;
        cout<<"\t\t"<<(char)(192+i+32)<<" = "<<192+i+32;
        cout<<"\t\t"<<(char)(192+i+48)<<" = "<<192+i+48<<endl;
    }
    cout<<(char)(168)<<" = 168\t\t"<<(char)(184)<<" = 184"<<endl;

    char arr[] = ""; //str of consonant -> what we check
    char str[] = ""; //test str
    int i = 0;

    cout<<str<<" --> ";

    //looking for consonants
    while(str[i] != '\0'){
        //checking if letter is consonant
        bool fl = false;
        int len = 0;
        while(arr[len] != '\0'){
            if(arr[len] == str[i])
                fl = true;
            len += 1;
        }
        if(fl){
            //turning consonant into capital one
            str[i] = (char)((int)str[i] - 32);
        }
        i += 1;
    }

    //output changed str
    cout<<str<<endl;
/* 
        task 2
*/
    int N ; // amount of word with min size
    char check_ch[2]; // arr of changing letters
    

    //getting amount of words and letters for check_ch
    ifstream in("input.txt");
    //checking if file is there
    if(!in.is_open()){
        //if there isnt file we get info from terminal
        cout<<"INPUT IS NOT FOUND"<<"ВВЕДИТЕ КОЛ-ВО И БУКВЫ В КОНСОЛЬ"<<endl;
        cout<<"N =";
        cin>>N;
        cout<<"буквы: ";
        cin>>check_ch;
        //checking amount of size of word
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1;
        }
    } else {
        //if file is there
        in>>N;
        in>>check_ch;
        //making letters into lowercase
        check_ch[0] = tolower(check_ch[0]);
        check_ch[1] = tolower(check_ch[1]);
        //output for check
        cout<<endl<<"N = "<<N<<endl;
        cout<<"Проверяемые буквы = "<<check_ch[0]<<" "<<check_ch[1]<<endl;
        in.close();
    }

    //getting text
    ifstream txt("text.txt");
    //checking text
    if(!txt.is_open()){
        cout<<"ТЕКСТА НЕТ";
        return 1;
    } else {

        string words[10]; //arr of words
        string word; //word form text
        string znaki(".,:?-();!\"'"); // + ... '' "" str of symbols
        i = 0; //index of word in arr words

        while(!txt.eof()){
            txt>>word;
            //lowering letters
            for(int j = 0;j<size(word);j++){
                word[j] = tolower(word[j]);
            }
            //making free of ...
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            //deleting symbols in the front of the word
            if(znaki.find(word[0]) != string::npos){
                word.erase(0,1);
            }
            //deleting symbols in the end of the word
            if(znaki.find(word[size(word)-1]) != string::npos){
                word.erase(size(word)-1,1);
            }
            //working with word
            if(word.find(check_ch[0]) != string::npos && word.find(check_ch[1]) != string::npos){
                //sorting arr of words
                //buble method
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
                //if amount is lower
                if(i < N){
                    //if word isnt in arr
                    if(end(words) == find(begin(words),end(words),word)){
                        words[i] = word;
                        i++;
                    }
                //if amount is more than needed
                } else {
                    //comparing len of words
                    for(int j = 0;j<N;j++){
                        if(size(words[j]) > size(word))
                            words[j] = word;
                            break;
                    }
                }
            }
        }
        //last sort (using funct because im lazy)
        sort(begin(words),words+i); 
        //opening output
        ofstream out("result.txt");
        for(int i = 0;i<N;i++){
            //output into file and terminal
            cout<<words[i]<<" ";
            out<<words[i]<<" ";
        }

        out.close();
    }

    txt.close();
    
    return 0;
}
