#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    //������������� ���������
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");
    //�������� ������
    ifstream in("cod.txt");
    if(!in.is_open()){
        cout<<"cod.txt is not found"<<endl;
        return 1;
    } else {
        string answer(""); //������ � �������
        string word; //������ ����������� �����
        string arr_of_nums("1234567890"); //������ ����
        while(!in.eof()){
            in>>word;
            //���� ������ ������ ����� = �����
            if(arr_of_nums.find(word[0]) != string::npos){
                //�������� ������������ �����
                int i = 1; //��� ����� �� �������� �� ����������� �����(������, ����� ����� = 146374 � �����)
                string num(""); //������ ���� �����
                //�������� �����
                while(word[i] != '\0'){
                    num += word[i-1];
                    i++;
                }
                //�������� ����� �� ������ ����� + ������
                answer+=string (stoi(num),word[size(word)-1]) + " ";
            //���� ����� ������������
            } else {
                int len = 0; //���-�� ��������
                while(word[len] != '\0'){
                    len++; //������� ���-��
                }
                //��������� ����� � ������ � ����������� � ����� + ������
                answer+=to_string(len) +word[0] + " ";
            }
        }
        in.close(); //�������� ����
        ofstream out("cod.txt"); //�������� ������
        cout<<answer<<endl; //����� � ������� ��� ��������
        out<<answer; //����� � ����
        out.close(); //�������� ������
    }
    return 0;
}