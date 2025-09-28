#include<iostream>
#include "Veera_Sept24_task3_DateAndTime.h"

int main(){
    std::cout<<"---Increment into next day---"<<std::endl;
    DateAndTime dt(12, 31, 2025, 23, 59, 58);

    for(int i=0;i<5;i++){
        dt.printStandard();
        std::cout<<std::endl;
        dt.tick();
    }
    return 0;
}