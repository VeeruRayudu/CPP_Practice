#include<iostream>
#include "Veera_Sept26_task2_Complex.h"

int main(){
    Complex x, y(4.3, 8.2), z(3.3, 1.1);

    std::cout<<"Initial values:\n";
    std::cout<<"x: "<<x<<"\ny: "<<y<<"\nz: "<<z<<std::endl;

    // addition
    x = y + z;
    std::cout<<"\nAddition x = y + z: "<<x<<" = "<<y<<" + "<<z<<std::endl;

    // subtraction
    x = y-z;
    std::cout<<"Subtraction x = y - z: "<<x<<" = "<<y<<" - "<<z<<std::endl;

    // multiplication
    x = y * z;
    std::cout<<"Multiplication x = y * z: "<<x<<" = "<<y<<" * "<<z<<std::endl;

    // equality
    std::cout<<"\nComparisons:\n";
    std::cout<<"y == z? "<<(y == z ? "true" : "false")<<std::endl;
    std::cout<<"y != z? "<<(y != z ? "true" : "false")<<std::endl;
    
    Complex user;
    std::cin>>user;
    std::cout<<"You entered: "<<user<<std::endl;

    return 0;
}
