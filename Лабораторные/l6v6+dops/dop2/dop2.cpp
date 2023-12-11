#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    //������������� ���������
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");

    int N ; // ���-�� ���� ��� �����
    char check_ch; // ������� �����
    string iskl; //����������
    //��������� ���-�� ���� � ���� �� ������
    ifstream in("input.txt");
    //�������� ������� �����
    if(!in.is_open()){
        //���� ����� ���, �� �������� �� �������
        cout<<"INPUT IS NOT FOUND"<<"������� ���-�� � ����� � �������"<<endl;
        cout<<"N =";
        cin>>N;
        cout<<"�����: ";
        cin>>check_ch;
        cout<<"����������: ";
        cin>>iskl;
        check_ch = tolower(check_ch); //��������� �� ������ ����������
        for(int j = 0;j<size(iskl);j++){
            iskl[j] = tolower(iskl[j]);
        }
        //���� ���-�� ���� (N) ��������
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1; //�����
        }
    } else {
        //���� ���� ������������, �������� ������
        in>>N;
        in>>check_ch;
        in>>iskl;
        //��������� ���������� ����� � ��������
        check_ch = tolower(check_ch);
        for(int j = 0;j<size(iskl);j++){
            iskl[j] = tolower(iskl[j]);
        }
        //����� ��� ��������
        cout<<endl<<"N = "<<N<<endl;
        cout<<"����������� ����� = "<<check_ch<<endl;
        cout<<"���������� = "<<iskl<<endl;
        in.close(); //��������� �����
    }

    //��������� ������
    ifstream txt("text.txt");
    //�������� ������� ������
    if(!txt.is_open()){ //���� ������ ���
        cout<<"������ ���";
        return 1;
    } else { //���� ���������� ������� �����
        string words[10]; //������ ����
        string word; //����� �� ������
        string znaki(".,:?-();!\"'"); // + ... '' "" ������ ��������
        int i = 0; //����� ����� � ������� ����
        
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
            //����������� �� ��������� x2
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            //����������� �� ����� ���������� � ������
            if(znaki.find(word[0]) != string::npos){
                word.erase(0,1);
            }
            //����������� �� ����� ���������� � �����
            if(znaki.find(word[size(word)-1]) != string::npos){
                word.erase(size(word)-1,1);
            }
            //��������� ����������� �����
            if(word[size(word)-1] == check_ch || word == iskl){ //���� ��������� ���� = ������� ��� ����� = ������
                if(word == iskl && word[size(word)-1] == check_ch) //���� ����� = ������ � ��������� ���� = �������
                    continue; //������� ���������
                //���������� ��������� (����� ����� ������������� �� �����)
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
                if(i < N){ //���� ���� ����� ��� ����� ����
                    //���� ����� ��� � �������, �� ��������� ��� � ������
                    if(end(words) == find(begin(words),end(words),word)){
                        words[i] = word;
                        i++;
                    }
                } else { //�������� ������� �� ���-�� ����
                    //���������� �� ������ ��� ��������� ����
                    for(int j = 0;j<N;j++){
                        if(size(words[j]) < size(word))
                            //��������� ������� ����� � �������
                            if(end(words) == find(begin(words),end(words),word)){
                                words[j] = word;
                                break; //����� �� �����
                        }
                    }
                }
            }
        }
        //�������� ������
        ofstream out("result.txt");
        for(int i = 0;i<N;i++){
            //����� � ���� � � ������� ��� ������������ ����������
            cout<<words[i]<<" ";
            out<<words[i]<<" ";
        }
        out.close(); //�������� ������
    }
    txt.close(); //�������� ������
    return 0;
}
