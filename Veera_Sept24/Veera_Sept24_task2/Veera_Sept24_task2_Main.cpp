#include<iostream>
#include "Veera_Sept24_task2_Date.h"

int main(){
    std::cout<<"--Test Case A: Next month---"<<std::endl;
    Date d1(1, 30, 2025);
    for(int i=0;i<3;i++){
        d1.print();
        std::cout<<std::endl;
        d1.nextDay();
    }

    std::cout<<"\n ----Test case B: Next Year---"<<std::endl;
    Date d2(12, 30, 2025);
    for(int i=0;i<3;i++){
        d2.print();
        std::cout<<std::endl;
        d2.nextDay();
    }

    std::cout<<"\n---Leap year test(feb 28, 2024)---"<<std::endl;
    Date d3(2, 28, 2024);
    for(int i=0;i<3;i++){
        d3.print();
        std::cout<<std::endl;
        d3.nextDay();
    }

    return 0;
}