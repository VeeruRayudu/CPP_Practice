#include<iostream>
#define SIZE 10

int main(){
    //a
    double array[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};

    //b
    double *nPtr;

    //c
    for(int i=0;i<SIZE;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<"\n";

    //d
    nPtr = array;
    nPtr = &array[0];

    //e
    for(int i=0;i<SIZE;i++){
        std::cout<<*(nPtr + i)<<" ";
    }
    std::cout<<"\n";

    //f
    for(int i=0;i<SIZE;i++){
        std::cout<<*(&array + 1)<<" ";
    }
    std::cout<<"\n";

    //g
    for(int j=0;j<SIZE;j++){
        std::cout<<nPtr[j]<<" ";
    }
    std::cout<<"\n";

    //h
    double element4 = array[3];
    element4 = *(array + 3);
    element4 = nPtr[3];
    element4 = *(nPtr + 3);

    //i
    std::cout<<"Address: "<<(nPtr+8)<<", Value: "<<*(nPtr + 8)<<std::endl;

    //j
    nPtr = &array[5];
    nPtr = nPtr - 4;
    std::cout<<"Address: "<<nPtr<<", Value: "<<*nPtr<<std::endl;







}