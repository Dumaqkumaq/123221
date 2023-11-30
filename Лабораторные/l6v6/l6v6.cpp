#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    system("chcp 1251");
    setlocale(LC_ALL,"RUSSIAN");
    int N ; // ���-�� ���� ��� �����
    
    //��������� ���-�� ���� � ���� �� ������
    ifstream in("input.txt");
    //�������� ������� �����
    if(!in.is_open()){
        //���� ����� ���, �� �������� � �������
        cout<<"��� ������"<<"������� ���-�� � �������"<<endl;
        cout<<"N =";
        cin>>N;
        //���� ���-�� ���� ��������
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1;
        }
    } else {
        //���� ���� ������������, �������� ������
        in>>N;
        //���� ���-�� ���� ��������
        if(N >10 || N <1){
            cout<<"WRONG N";
            return 1;
        }
        //����� ��� ��������
        cout<<endl<<"N = "<<N<<endl;
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
        int num_arr[10]; // ������ ���� ����
        /*
            ��������� ��������� ����(��� ����� ����������):
            words -> ������ ������ ����
            num_arr -> ������ ���-�� �������

            ��������: words = {����, ���, ����, ��������}
            ������ ����� "����" ����� 0 � ���-�� ������� ����� 2, �����
            ������ � ������� 0 � num_arr ����� 2
            ����� -> num_arr = {2}
            ����� �������� �� ����� �������
            ����� ���� �������� ��������: num_arr = {2, 1, 2, 4}

            ��������������, ����� ������� � ���-�� ������� ����� 10, �.�. ���� ����� ����� ���� 10
        */
        string word; //����� �� ������
        string znaki(".,:?-();!\"'"); // + ... '' "" ������ ��������
        string chk("���������"); // ������ ����������� ����
        int i = 0; //����� ����� � ������� ����

        while(!txt.eof()){
            int len = 0;// ����� ������� � �����
            int count = 0;// ���-�� ������� � ������� �����
            txt>>word;
            //��������� ����� �� ������
            for(int j = 0;j<size(word);j++){
                word[j] = tolower(word[j]);
            }
            //����������� �� ���������
            if(word.find("...") != string::npos){
                word.erase(word.find("..."),3);
            }
            //������ ��� ������� ���������(�� ������, ���� ������� � � ����� ����)
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
            //������� ���-�� �������
            while(word[len] != '\0'){
                if(chk.find(word[len]) != string::npos) // ���� ������� � �����
                    count += 1; // +1, ���� ����� ���� �������
                len++; // ��������� �� ����� ������ �����
            }
            //�������� � ��������
            if(i < N){ //���� ����� ��� ����
                if(end(words) == find(begin(words),end(words),word)){ //���� ����� �� ����� � �������
                    //���� ��� ���, �� ���������:
                    words[i] = word; // <-- � ������ ����
                    num_arr[i] = count; // <-- � ������ ���-�� ��������
                    i++;
                }
            } else { //���� ����� ��� ���
                //���������� ���������
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
                //���������� ���-�� ������� ���� � ������� � ���-�� � ������� �����
                for(int b = 0;b<N;b++){ // ���������� �� ������
                    if(count>num_arr[b]){ // ���������� ������� ���-�� � ���-�� ����� ��� �������� b
                        if(end(words) == find(begin(words),end(words),word)){ // ������� ��� ������� � �������
                                //���� ������ ����� ���, ��:
                                words[b] = word; // <-- ������ ����� � �������
                                num_arr[b] = count; // <-- ������ ���-�� �������� � ������ �������
                                break;
                        }
                    }
                }
            }
        }
        //���������� � ������� �������� ����� �������
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
        //�������� ������
        ofstream out("result.txt");
        for(int g = 0;g<N;g++){
            //����� � ���� � � ������� ��� ������������ ����������
            cout<<words[g]<<" --> "<<num_arr[g]<<endl;
            out<<words[g]<<" --> "<<num_arr[g]<<endl;
        }
        out.close();
    }
    txt.close();
    
    return 0;
}
