#include<iostream>
#include "Veera_Sept24_task4_ModifiedTime.h"

int main(){
    ModifiedTime t1;
    std::cout<<"--Testing Valid Time---"<<std::endl;
    if(!t1.setTime(14, 30, 45)){
        std::cout<<"Error:Invalid Time!"<<std::endl;
    }else{
        t1.printUniversal();
        std::cout<<" ";
        t1.printStandard();
        std::cout<<std::endl;
    }

    std::cout<<"\n--Testing invalid hour--"<<std::endl;
    if(!t1.setHour(25)){
        std::cout<<"Error: invalid hour, must be(0-23)"<<std::endl;
    }

    std::cout<<"\n--Testing invalid minute--"<<std::endl;
    if(!t1.setMinute(80)){
        std::cout<<"Error: invalid minute, must be(0-59)"<<std::endl;
    }

    std::cout<<"\n--Testing invalid second--"<<std::endl;
    if(!t1.setSecond(80)){
        std::cout<<"Error: invalid second, must be(0-59)"<<std::endl;
    }

    return 0;

}