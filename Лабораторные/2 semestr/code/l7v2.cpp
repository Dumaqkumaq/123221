#include <iostream>

template<typename T>
class matrix{
    T** arr;
    int rows;
    int columns;

    T** copy(int rows, int columns, T** arr, T** other_arr){
        arr = new T*[rows];
        for(int i = 0; i < rows; i++){
            arr[i] = new T[columns];
            for(int j = 0; j < columns; j++){
                arr[i][j] = other_arr[i][j];
            }
        }
        return arr;
    }
    // T** del(int rows, int columns, T** arr){
        
    // }
public:
//конструкторы
    //по умолчанию
    matrix(){
        rows = 0;
        columns = 0;
        arr = nullptr;
    }
    //по заданным данным
    matrix(int r, int c) {
        if( r > 4) {
            std::cout<<"too big row\n";
            rows = 4;
        } else {rows = r;}
        if(c > 4){
            std::cout<<"too big column\n";
            columns = 4;
        }else {columns = c;}
        arr = new T*[rows];
        for(int i = 0; i < rows; i++){
            arr[i] = new T[columns];
            for(int j = 0; j < columns; j++){
                arr[i][j] = 0;
            }
        } 
    }
    //копирования
    matrix(matrix& other) : 
        rows(other.rows), 
        columns(other.columns) 
        {
        arr = new T*[rows];
        for(int i = 0; i < rows; i++){
            arr[i] = new T[columns];
            for(int j = 0; j < columns; j++){
                arr[i][j] = other.arr[i][j];
            }
        }
    }
//деструктор
    ~matrix(){
        for(int i = 0; i < rows; i++){
            delete[] arr[i];
        }
        delete[] arr;
        arr = nullptr;
    }
//геттеры
    int getColumns(){
        return columns;
    }
    int getRows(){
        return rows;
    }
//вспомогательная функция
    void print(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                std::cout<<arr[i][j]<<"\t";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
//операторы
    //для удобства
    T& operator () (int i){
        return arr[i];
    }
    T& operator () (int i, int j){
        return arr[i][j];
    }
    //сумма
    matrix& operator += (matrix<T>& other){
        if((rows != other.rows) || (columns != other.columns)){
            std::cout<<"dont same size\n";
            return *this;
        }
        for(int i =0; i< rows; i++){
            for(int j = 0; j < columns; j++){
                arr[i][j] += other(i,j);
            }
        }
        return *this;
    }
    matrix operator + (matrix<T>& other){
        if((rows != other.rows) || (columns != other.columns)){
            std::cout<<"dont same size\n";
            return *this;
        }
        for(int i =0; i< rows; i++){
            for(int j = 0; j < columns; j++){
                arr[i][j] += other(i,j);
            }
        }
        return *this;
    }
    //разность
    matrix& operator -= (matrix<T>& other){
        if((rows != other.rows) || (columns != other.columns)){
            std::cout<<"dont same size\n";
            return *this;
        }
        for(int i =0; i< rows; i++){
            for(int j = 0; j < columns; j++){
                arr[i][j] -= other(i,j);
            }
        }
        return *this;
    }
    matrix& operator - (matrix<T>& other){
        if((rows != other.rows) || (columns != other.columns)){
            std::cout<<"dont same size\n";
            return *this;
        }
        for(int i =0; i< rows; i++){
            for(int j = 0; j < columns; j++){
                arr[i][j] -= other(i,j);
            }
        }
        return *this;
    }
    //произведение
    matrix& operator *= (matrix<T>& other){
        if(columns != other.rows){
            std::cout<<"can not mult\n";
            matrix tmp(1,1);
            tmp(1,1) = 9999;
            for(int i = 0; i < rows; i++){
                delete[] arr[i];
            }
            delete[] arr;
            arr = nullptr;
            this->rows = tmp.rows;
            this->columns = tmp.columns;
            
            arr = copy(rows,columns,arr,tmp.arr);
            return *this;
        }
        matrix tmp(columns, other.rows);
        for(int i = 0; i < rows;i++){
            for(int j = 0; j < columns; j++){
                for(int k = 0; k < other.rows; k++){
                    tmp(j,k) += arr[j][i] * other(i,j);
                }
            }
        }
        for(int i = 0; i < rows; i++){
                delete[] arr[i];
            }
            delete[] arr;
            arr = nullptr;
            this->rows = tmp.rows;
            this->columns = tmp.columns;
            
            arr = copy(rows,columns,arr,tmp.arr);
        return *this;
    }
    matrix& operator * (matrix<T>& other){
        if(columns != other.rows){
            std::cout<<"can not mult\n";
            matrix tmp(1,1);
            tmp(1,1) = 9999;
            for(int i = 0; i < rows; i++){
                delete[] arr[i];
            }
            delete[] arr;
            arr = nullptr;
            this->rows = tmp.rows;
            this->columns = tmp.columns;
            
            arr = copy(rows,columns,arr,tmp.arr);
            return *this;
        }
        matrix tmp(columns, other.rows);
        for(int i = 0; i < rows;i++){
            for(int j = 0; j < columns; j++){
                for(int k = 0; k < other.rows; k++){
                    tmp(j,k) += arr[j][i] * other(i,j);
                }
            }
        }
        for(int i = 0; i < rows; i++){
                delete[] arr[i];
            }
            delete[] arr;
            arr = nullptr;
            this->rows = tmp.rows;
            this->columns = tmp.columns;
            
            arr = copy(rows,columns,arr,tmp.arr);
        return *this;
    }
    //присваивание
    matrix& operator = (matrix& other){
        if(this != &other){
            for(int i = 0; i < rows; i++){
                delete[] arr[i];
            }
            delete[] arr;
            arr = nullptr;
            this->rows = other.rows;
            this->columns = other.columns;
            
            arr = copy(rows,columns,arr,other.arr);
        }
        return *this;
    }
    //вывод
    friend std::ostream& operator << (std::ostream& stream, matrix<T>& matrx){
        stream<<"Matrix\n";
        for(int i = 0; i < matrx.getRows();i++){
            for(int j = 0; j < matrx.getColumns();j++){
                stream<<matrx(i,j)<<"\t";
            }
            stream<<"\n";
        }
        return stream;
    }
    //ввод
    friend std::istream& operator >> (std::istream& stream, matrix<T>& matrx){
        printf("Write elements of matrix [%d;%d]:\n",matrx.getRows(),matrx.getColumns());
        int rows = matrx.getRows();
        int columns = matrx.getColumns();
        for(int i = 0; i < rows;i++){
            for(int j = 0; j < columns; j++){
                printf("---element {%d;%d}: ",i+1,j+1);
                stream >> matrx(i,j);
            }
        }
        return stream;
    }
//функции и методы
    //вспомогательное копирование
    T** help(T** arr1,int number){
        for(int i = number; i < rows; i++){
            for(int j =0;j<columns;j++){
                arr1[i-1][j] = arr1[i][j];
            }
        }
        return arr1;
    }
    //функция удаления ряда
    void delete_row(int num){
        if((num > rows) || (num <= 0)){
            std::cout<<"not right number of row\n";
        } else if(num == rows){
            delete[] arr[rows-1];
            rows--;
        } else {
            arr = help(arr,num);
            delete[] arr[rows-1];
            rows--;
        }
    }
    //метод вычисления определителя
    double opredelitel(){
        if(rows != columns){
            std::cout<<"opredelitel can not be found\n";
            return 9999;
        }
        int num = 0;
        switch(rows){
            case 0: num = 0;break;
            case 1: num = arr[0][0]; break;
            case 2: num = arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0]; break;
            case 3: num = arr[0][0]*arr[1][1]*arr[2][2]+arr[0][1]*arr[1][2]*arr[2][0]+arr[0][2]*arr[2][1]*arr[1][0]-arr[0][2]*arr[1][1]*arr[2][0]-arr[0][1]*arr[1][0]*arr[2][2]-arr[0][0]*arr[1][2]*arr[2][1];break;
        }
        return num;
    }
};





int main(){
    matrix<double> arr(3,1);
    matrix<bool> arr2(2,2);
    //arr.print();

    //arr2.print();
    // arr2 = arr;
    
    std::cin>>arr;
    std::cout<<arr;
    arr.delete_row(2);
    std::cout<<arr;
    // std::cin>>arr;
    // std::cout<<arr;
    // arr2 *= arr;
    // std::cout<<arr2;


    return 0;
}