#include<iostream>
#include<fstream>
#include<algorithm> // for max_element and min_element
using namespace std;

void input(int *num_ptr);
void input(float *num_ptr);
void input(double *num_ptr);
void input(int *Nptr,int matrix[11][11]);
void input(int *Nptr,int matrix[11][11], int *num_ptr);
void input(int *Nptr,int matrix[11][11], float *num_ptr);
void input(int *Nptr,int matrix[11][11], double *num_ptr);
bool check_same_str(int matrix[11][11], int N);
void change_min_element(int matrix[11][11], int N);
int multiply(int num);
double multiply(float num);
double multiply(double num);
void output(int num);
void output(float num);
void output(double num);
void output(int matrix[11][11],int N);
void output(int matrix[11][11],int N, int num);
void output(int matrix[11][11],int N, float num);
void output(int matrix[11][11],int N, double num);


//mult of numbers of num
int multiply(int num){
    if(num == 0)
        return 0;
    int result = 1;
    if(num < 0){
        result = (-1);
        num = abs(num);
    }
    while(num > 0){
        if(num%10!=0)
            result*=num%10;
        num /=10;
    }
    return result;
}
//returning numbers after dig point
double multiply(float num){
    return num-(int)num;
}
//returning numbers after dig point
double multiply(double num){
    return num-(int)num;
}
//getting matrix from input
void input(int *Nptr, int matrix[11][11]){
    ifstream in("input.txt");
    if(!in.is_open()){
        cout<<"INPUT NOT FOUND"<<endl;
    } else {
        //getting amount of str
        in>>*Nptr;
        //getting elements
        for(int i = 0;i<*Nptr;i++){
            for(int j = 0;j<*Nptr;j++){
                in>>matrix[i][j];
            }
        }
        cout<<endl;
        in.close();
    }
}
//getting number from input
void input(int *num_ptr){
    ifstream in("input.txt");
    if(!in.is_open()){
        cout<<"INPUT NOT FOUND"<<endl;
    } else {
        //getting number
        in>>*num_ptr;
        in.close();
    }
}
//getting number from input
void input(float *num_ptr){
    ifstream in("input.txt");
    if(!in.is_open()){
        cout<<"INPUT NOT FOUND"<<endl;
    } else {
        //getting number
        in>>*num_ptr;
        in.close();
    }
}
//getting number from input
void input(double *num_ptr){
    ifstream in("input.txt");
    if(!in.is_open()){
        cout<<"INPUT NOT FOUND"<<endl;
    } else {
        //getting number
        in>>*num_ptr;
        in.close();
    }
}
//getting matrix and number from input
void input(int *Nptr, int matrix[11][11], int *num_ptr){
    ifstream in("input.txt");
    if(!in.is_open()){
        cout<<"INPUT NOT FOUND"<<endl;
    } else {
        //getting amount of str
        in>>*Nptr;
        //getting elements
        for(int i = 0;i<*Nptr;i++){
            for(int j = 0;j<*Nptr;j++){
                in>>matrix[i][j];
            }
        }
        in>>*num_ptr;
        in.close();
    }
}
//getting matrix and number from input
void input(int *Nptr, int matrix[11][11], float *num_ptr){
    ifstream in("input.txt");
    if(!in.is_open()){
        cout<<"INPUT NOT FOUND"<<endl;
    } else {
        //getting amount of str
        in>>*Nptr;
        //getting elements
        for(int i = 0;i<*Nptr;i++){
            for(int j = 0;j<*Nptr;j++){
                in>>matrix[i][j];
            }
        }
        in>>*num_ptr;
        in.close();
    }
}
//getting matrix and number from input
void input(int *Nptr, int matrix[11][11], double *num_ptr){
    ifstream in("input.txt");
    if(!in.is_open()){
        cout<<"INPUT NOT FOUND"<<endl;
    } else {
        //getting amount of str
        in>>*Nptr;
        //getting elements
        for(int i = 0;i<*Nptr;i++){
            for(int j = 0;j<*Nptr;j++){
                in>>matrix[i][j];
            }
        }
        in>>*num_ptr;
        in.close();
    }
}
//output
void output(int matrix[11][11], int N){
    cout<<"matrix is out"<<endl;
    ofstream out("result.txt");
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            out<<matrix[i][j]<<"\t";
        }
        out<<endl;
    }
    out.close();
}
void output(int num){
    cout<<"number is out"<<endl;
    ofstream out("result.txt");
    out<<num;
    out.close();
}
void output(float num){
    cout<<"number is out"<<endl;
    ofstream out("result.txt");
    out<<num;
    out.close();
}
void output(double num){
    cout<<"number is out"<<endl;
    ofstream out("result.txt");
    out<<num;
    out.close();
}
void output(int matrix[11][11],int N, int num){
    cout<<"matrix and number are out"<<endl;
    ofstream out("result.txt");
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            out<<matrix[i][j]<<"\t";
        }
        out<<endl;
    }
    out<<num;
    out.close();
}
void output(int matrix[11][11],int N, float num){
    cout<<"matrix and number are out"<<endl;
    ofstream out("result.txt");
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            out<<matrix[i][j]<<"\t";
        }
        out<<endl;
    }
    out<<num;
    out.close();

}
void output(int matrix[11][11],int N, double num){
    cout<<"matrix and number are out"<<endl;
    ofstream out("result.txt");
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            out<<matrix[i][j]<<"\t";
        }
        out<<endl;
    }
    out<<num;
    out.close();

}
//chack same string in matrix
bool check_same_str(int matrix[11][11], int N){
    for(int i = 0;i<N-1;i++){
        for(int j = i+1;j<N;j++){
            if(equal(matrix[i],matrix[i]+N,matrix[j])){
                return true;
            }
        }
    }
    return false;
}
//changing min element to max one in matrix
void change_min_element(int matrix[11][11],int N){
    //max element of matrix
    int max = *max_element(matrix[0],matrix[0]+N);
    for(int i = 1;i<N;i++){
        max = std::max(max,*max_element(matrix[i],matrix[i]+N));
    }
    //min element of matrix
    int min = *min_element(matrix[0],matrix[0]+N);
    for(int i = 1;i<N;i++){
        min = std::min(min,*min_element(matrix[i],matrix[i]+N));
    }
    //change min element into max element
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(matrix[i][j] == min)
                matrix[i][j] = max;
        }
    }
}