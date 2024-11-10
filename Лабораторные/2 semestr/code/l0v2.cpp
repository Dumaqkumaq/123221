#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
//фиксированный возврат строки (не через К=номер варианта)
using namespace std;
string filling(float** matrix, int M, int N);
void matrix_print(float** A, int M, int N);

int main(){
//  system("chcp 1251");
    srand(time(0)); // seed = time
    
    int M = rand() % (5-3+1) + 3; // % -> right limit
    int N = rand() % (5-3+1) + 3; // + -> left limit
    // M = 5;
    // N = 5;
//  creating matrix A[M][N]
    float** A = new float*[M];
    for(int i = 0;i<M;i++){
        A[i] = new float[N];
    }    
//  filling matrix and string
    string str = filling(A, M, N);
//  printing matrix
    matrix_print(A,M,N);
//  output string
    ofstream out;
    out.open("out.txt",std::ios::app); 
    if(out.is_open()){
        cout<<"FILE IS OPENED"<<endl;
        out<<str;
    } else {
        cout<<"FILE ISNT OPENED"<<endl;
    }
    out.close();
    
    return 0;
}

string filling(float** A, int M, int N){
    for(int i = 0;i<M;i++){
        if(i == M/2){
//          if main zone
            for(int j = 0;j<N;j++){
//              if main and additional zone
                if(A[i-1][j] == -2){
                    A[i][j] = 0;
//              if only main zone
                } else 
                    A[i][j] = 2;
            }
//          if matrix is even
            if(M%2==0){
                A[i-1] = A[i];
            }
        } else {
            for(int j = 0;j<N;j++){
//              if additional zone
                if(j == (N/2)){
                    A[i][j] = -2;
//                  if matrix is even
                    if(N%2==0)
                        A[i][j-1] = A[i][j];
//              if not additional and not main zone
                } else {
                    int ran_num = rand(); 
                    A[i][j] = ((ran_num % 99 +1) / 1000.0) * pow(-1,ran_num%10);
                }
            }
        }
        
    }
    return "Ёё";
}
void matrix_print(float** A, int M, int N){
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
}