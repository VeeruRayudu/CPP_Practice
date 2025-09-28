#include<iostream>
#include "Veera_Sept26_task4_RelationalNumber.h"

int main() {
    RationalNumber r1(2, 4);  
    RationalNumber r2(3, 9);  
    RationalNumber r3(-4, -8); 
    RationalNumber r4(5, -15); 

    //fractions
    std::cout<<"r1 = "<<r1<<"\n";
    std::cout<<"r2 = "<<r2<<"\n";
    std::cout<<"r3 = "<<r3<<"\n";
    std::cout<<"r4 = "<<r4<<"\n\n";

    //arithmetic operations
    std::cout<<"r1 + r2 = "<<(r1 + r2)<<"\n";
    std::cout<<"r1 - r2 = "<<(r1 - r2)<<"\n";
    std::cout<<"r1 * r2 = "<<(r1 * r2)<<"\n";
    std::cout<<"r1 / r2 = "<<(r1 / r2)<<"\n\n";

    //comparision operations
    std::cout<<std::boolalpha;
    std::cout<< "r1 == r2 ? "<<(r1 == r2)<<"\n";
    std::cout<< "r1 != r2 ? "<<(r1 != r2)<<"\n";
    std::cout<< "r1 > r2 ? "<<(r1 > r2)<<"\n";
    std::cout<< "r1 < r2 ? "<<(r1 < r2)<<"\n";

    return 0;
}
