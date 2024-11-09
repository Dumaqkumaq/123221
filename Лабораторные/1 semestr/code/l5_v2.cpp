#include<iostream>
using namespace std;
/* 
    1.	Дана последовательность натуральных чисел {A1, A2, …, AK}. 
    Упорядочить её по возрастанию, если есть пара одинаковых чисел подряд.
    2.	Ввести размеры и заполнить матрицу T [M x N] целыми числами.
    Найти столбец с минимальным кол-вом положительных чисел 
    и заменить все значения в нем на 100.
 */

int main(){
    
        //Задание 1

    //получение длины массива с числами
    int len_arr;
    cout<<"Write a length of array: ";
    cin>>len_arr;

    //обработка случая слишком большой длины
    if(len_arr >= 20 || len_arr <= 0){
        cout<<"WRONG LENGHT LENGTH";
        return 1;

    }

    //создание массива
    int arr[20];

    //заполнение массива случ числами и их вывод
    cout<<"Write numbers for ur array: "<<endl;
    for(int i = 0; i!= len_arr;i++){
        cin>>arr[i];
    }

    //вывод введенного массива
    cout<<"Ur array => [ ";
    for(int i = 0;i<len_arr;i++)cout<<arr[i]<<" ";
    cout<<"]"<<endl;

    //поиск повторных чисел в массиве
    bool fl = 0;
    if(len_arr > 1){
        for(int i = 1; i != len_arr;i++){
            if(arr[i] == arr[i-1]) 
                fl = 1;

        }
    }

    //обработка случая с повторами
    if(fl){
        //сортировка
        bool fl1 = true;
        while(fl1){
            fl1 = false;
            for(int i = 1;i<len_arr;i++){
                if(arr[i] < arr[i-1]){
                    swap(arr[i],arr[i-1]);
                    fl1 = true;
            }
        } 
    }

        //вывод массива
        cout<<"Your array will be sorted\nYour array => [ ";
        for(int i = 0; i!= len_arr;i++){
            cout<<arr[i]<<" ";

        }
        cout<<"]"<<endl;

    } else {
        cout<<"Your array wont be sorted"<<endl;
    }
    
        //Задание 2
    

    // len_arr = столбики = columns
    // rows = строчки
    int rows;

    //получение размеров матрицы
    cout<<"Write rows and columns of matrix: ";
    cin>>rows>>len_arr;

    //проверка размеров матрицы
    if((rows >= 10)||(len_arr >= 10)){
        cout<<"MATRIX IS TOO BIG";
        return 1;
    }

    int matrix[10][10];

    //заполнение матрицы
    cout<<"Write numbers of matrix: "<<endl;
    for(int i = 0;i != rows;i++){
        for(int j = 0;j != len_arr;j++){
            cin>>matrix[i][j];

        }
        cout<<endl;

    }
    cout<<"--------------------"<<endl;

    int min_column; // мин столб
    int amount_of_natur_num; // мин кол-во натур чисел в  текущ столбе
    int min_amount; // мин знач в мин столбе

    for(int j = 0; j != len_arr;j++){
        amount_of_natur_num = 0; // обнуляем кол-во натур чисел
        
        // считаем кол-во натур чисел в столбе
        for(int i = 0; i != rows; i++){
            if(matrix[i][j] > 0){
                amount_of_natur_num++;

            }
        }
        //находим столбец с мин ко-во натур числами
        if(min_amount > amount_of_natur_num){
            min_amount = amount_of_natur_num;
            min_column = j;
        }
    }

    //вывод матрицы до изменений
    cout<<"Ur matrix is =>"<<endl;
    for(int i = 0;i != rows;i++){
        for(int j = 0;j != len_arr;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<"--------------------"<<endl;

    // превращаем столб нужного столба в 100
    for(int i = 0; i != rows;i++){
        matrix[i][min_column] = 100;
    }

    // вывод измененного массива
    for(int i = 0;i != rows;i++){
        for(int j = 0;j != len_arr;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;

    } 
}