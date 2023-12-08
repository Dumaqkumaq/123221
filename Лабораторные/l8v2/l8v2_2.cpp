#include<iostream>
using namespace std;
//Использовать в программе только: 
//N, M, A[M][N], B[?][?], defA, defB, temp
//Методы new, delete, и др..
int main(){
    int M,N;
    int defA = 0,defB = 0; // m-норма
    //получение размеров матрицы
    cout<<"M = ";
    cin>>M;
    cout<<"N = ";
    cin>>N;
    //создание матрицы A
    int** A = new int*[M];
    for(int i = 0;i<M;i++){
        A[i] = new int[N];
    }
    //заполнение матрицы А по правилу: Aij = 10(i+1) + (j+1)
    //+ нахождение m-нормы
    for(int i = 0;i<M;i++){
        int temp = 0; //сумма текущей строки
        for(int j = 0;j<N;j++){
            A[i][j] = 10*(i+1)+(j+1); //значение элемента i-строки j-столбика
            temp += abs(A[i][j]); //прибавляем модуль текущего элемента к сумме
            cout<<A[i][j]<<" "; //вывод для наглядности
        }
        cout<<endl;
        defA = max(defA,temp); //находим m-норму(макс из текущей строки и макс предыдущего значения)
    }
    //cout<<"defA --> "<<defA<<endl; //вывод для наглядности
    cout<<endl;
    //создание новой матрицы B(B=At)
    int** B = new int*[N];
    for(int i = 0;i<N;i++){
        B[i] = new int[M];
    }
    //заполнение матрицы В
    for(int i = 0;i<N;i++){
        int temp = 0; //сумма текущей строки
        for(int j = 0;j<M;j++){
            B[i][j] = A[j][i]; //транспозируем элементы матрицы А
            temp += abs(B[i][j]); //прибавляем модуль текущего элемента к сумме
            cout<<B[i][j]<<" "; //вывод для наглядности
        }
        cout<<endl;
        defB = max(defB,temp); //находим m-норму
    }
    cout<<"defA --> "<<defA<<endl; //вывод для наглядности
    cout<<"defB --> "<<defB<<endl; //вывод для наглядности
    //сравнение норм
    if(defA>defB)
        cout<<"defA > defB"<<endl;
    else
        cout<<"defB > defA"<<endl;
    
    for(int i = 0;i<M;i++){
        delete[] A[i];
    }
    delete[] A;
    for(int i = 0;i<N;i++){
        delete[] B[i];
    }
    delete[] B;
    return 0;
}
