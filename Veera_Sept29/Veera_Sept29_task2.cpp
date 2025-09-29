#include<iostream>
#define SIZE 100

int main(){
    double number1 = 7.3f;
    double *fPtr;  //a
    fPtr = &number1;  //b
    std::cout<<*fPtr<<std::endl; //c
    double number2 = *fPtr;  //d
    std::cout<<number2<<std::endl;  //e
    std::cout<<&number1<<std::endl;  //f
    std::cout<<fPtr<<std::endl;  //g

}