#include<iostream>
#include"func.cpp"
using namespace std;
//нужно изменить функции для успешной сдачи:
//  1. поменять void на возвращаемый тип
//  2. убрать ссылки
//  3. получать данные в num и N с помощью return в функции
int main(){
    int matrix[11][11];
    int N = 0;
    float num = 0;
    int *N_ptr = &N; //это убрать
    float *num_ptr = &num; //это убрать

    input(N_ptr,matrix,num_ptr);
    
    if(check_same_str(matrix,N)){
        change_min_element(matrix,N);
    }
    
    output(matrix,N,multiply(num));
    
    return 0;
}
