#include<iostream>
using namespace std;
// Использовать в программе только: 
// K, A[K], S, tempб, flag, dop1?, dop2? + итераторы циклов
int main(){
    int K;
    cout<<"length of A: ";
    cin>>K;
    //динамик массик
    int* A = (int*)calloc(K,sizeof(int));
    //заполнение массива
    for(int i = 0;i<K;i++){
        A[i] = i+1;
        cout<<A[i]<<" ";
    }
    cout<<endl;
    //увеличение\уменьшение размера массива
    int S;
    cout<<"S = ";
    cin>>S;
    //изменение размера
    A =(int*)realloc(A,(K+S)*sizeof(int));
    if(S<0){
        //если срез
        cout<<"CUT"<<endl;
    } else {
        //если увеличение
        bool flag = false; // если есть два одинаковых числа подряд
        cout<<"NEW NUMBERS: "<<endl;
        //заполняем новыми числами с консоли
        cin>>A[K];
        for(int i = K+1;i<(S+K);i++){
            if(!flag){
                //если нет одинаковых чисел
                cin>>A[i];
            } else {
                //если есть одинаковые числа
                A[i] = 0;
            }
            //проверка наличия одинаковых чисел
            if(A[i]==A[i-1]){
                flag = true;
            }
        }
    }
    //вывод измененного массива
    for(int i = 0;i<K+S;i++){
        cout<<A[i]<<" ";
    }
    //освобождение памяти
    free(A);
    
    return 0;
}
