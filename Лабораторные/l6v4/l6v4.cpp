#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
//�������� ����� 
//
//

int main(){
    //������������� ���������
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");
/* 
        ������� 1
*/
    //����� ���������
    for(int i = 0;i<16;i++){
        cout<<(char)(192+i)<<" = "<<192+i;
        cout<<"\t\t"<<(char)(192+i+16)<<" = "<<192+i+16;
        cout<<"\t\t"<<(char)(192+i+32)<<" = "<<192+i+32;
        cout<<"\t\t"<<(char)(192+i+48)<<" = "<<192+i+48<<endl;
    }
    cout<<(char)(168)<<" = 168\t\t"<<(char)(184)<<" = 184"<<endl;

    char arr[] = "��������������������"; //������ ������ ��������
    char str[100] = "��� �������� ������"; //���������� ������
    char str_tmp[100] = ""; //������-�����
    int i = 0; //����� �������� ���������� ������
    int i_tmp = 0; //����� ��������� ������-������
    //���� ���������� ������ ������(������ ����� � �������)
    if(str[0]=='\0'){
        cout<<"������� ������: ";
        cin>>str;
    }
    cout<<str<<" --> "; //����� ���������� ������

    //���� �� ������ ��� ���������� ����
    while(str[i] != '\0'){
        //�������� ������� �� ����
        bool fl = false;
/* 
*         ������� ����:
*               ����� ������� ���������� ������ 
*               � ��������� ��� �� ������� � "������ ��������"
*               ���� ��� ����, �� ���������� ������ � ������-�����
*               ���� ������, �� ���������� �������
*/
        int len = 0;
        while(arr[len] != '\0'){
            char simvB = tolower(str[i]); //��������� ������ �������(� -> �)
            if(arr[len] == simvB) //���� ������ ������ �������� ����
                fl = true; //���� = ������
            len += 1;
        }
        if(!fl){ //���� ������ ������� �� ����
            str_tmp[i_tmp] = str[i]; //���������� ������ ������� � ������-�����
            i_tmp++; //��������� �� ���� ������� � ������-�����
        }
        i += 1; //��������� �� ���� ������ � ���������� ������
    }
    //����� ������
    cout<<str_tmp<<endl;
/* 
        ������� 2
*/
 /*    int N ; // ���-�� ���� ��� �����
    string check_ch; // ������ ����������� ����
    
    //��������� ���-�� ���� � ���� �� ������
    ifstream in("input.txt");
    //�������� ������� �����
    if(!in.is_open()){
        //���� ����� ���, �� �������� � �������
        cout<<"INPUT IS NOT FOUND"<<"������� ���-�� � ����� � �������"<<endl;
        cout<<"N =";
        cin>>N;
        cout<<"�����: ";
        cin>>check_ch;
        //���� ���-�� ���� ��������
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1;
        }
    } else {
        //���� ���� ������������, �������� ������
        in>>N;
        in>>check_ch;
        //��������� ���������� ����� � ��������
        int j = 0;
        while(check_ch[j] != '\0'){

        }
        //����� ��� ��������
        cout<<endl<<"N = "<<N<<endl;
        cout<<"����������� ����� = "<<check_ch<<endl;
        in.close();
    }

    //��������� ������
    ifstream txt("text.txt");
    //�������� ������� ������
    if(!txt.is_open()){
        cout<<"������ ���";
        return 1;
    } else {
        string words[10]; //������ ����
        string word; //����� �� ������
        string znaki(".,:?-();!\"'"); // + ... '' "" ������ ��������
        i = 0; //����� ����� � ������� ����

        while(!txt.eof()){
            txt>>word;
            //��������� ����� �� ������
            for(int j = 0;j<size(word);j++){
                word[j] = tolower(word[j]);
            }
            //����������� �� ���������
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            //�� ���� ������
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            //����������� �� ������ ���������� � ������
            if(znaki.find(word[0]) != string::npos){
                word.erase(0,1);
            }
            //����������� �� ������ ���������� � �����
            if(znaki.find(word[size(word)-1]) != string::npos){
                word.erase(size(word)-1,1);
            }
            //��������� ����������� �����
            if(word.find(check_ch[0]) != string::npos && word.find(check_ch[1]) != string::npos){
                //���������� ������� ����
                //����� ���� ����� �������, ������� ��������� ��������
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
                //���� �� �������� ������� �� ���-�� ����
                if(i < N){
                    //���� ����� ��� � �������
                    if(end(words) == find(begin(words),end(words),word)){
                        words[i] = word;
                        i++;
                    }
                //�������� ������� �� ���-�� ����
                } else {
                    //���������� �� ������ ��� ��������� ����
                    for(int j = 0;j<N;j++){
                        if(size(words[j]) > size(word))
                            //��������� ������� ����� � �������
                            if(end(words) == find(begin(words),end(words),word)){
                                words[j] = word;
                                break;
                        }
                    }
                }
            }
        }
        //�������� ���������� (��� ��� ���� ��������)
        sort(begin(words),words+i); 
        //�������� ������
        ofstream out("result.txt");
        for(int i = 0;i<N;i++){
            //����� � ���� � � ������� ��� ������������ ����������
            cout<<words[i]<<" ";
            out<<words[i]<<" ";
        }
        out.close();
    }
    txt.close();
     */
    return 0;
}