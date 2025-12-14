#include <iostream>
#include "4887766_MD3_Task2_DTC.h"

int main(){
    DTC dtc1("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, Severity::CRIT, true, false, true, "Engine", "ECU_01");

    DTC dtc2("P0301", "Cylinder 1 Misfire Detected", false, 3, 1625247600, Severity::INFO, true, false, true, "Engine", "Exhaust");

    if(dtc1 == dtc2){
        std::cout<<"Both objects codes and system are same\n"<<std::endl;
    }else{
        std::cout<<"Both objects codes and system are not same\n"<<std::endl;
    }

    if(dtc1 != dtc2){
        std::cout<<"Either the code or system differ from both objects\n"<<std::endl;
    }else{
        std::cout<<"Either the code or system do not differ from both objects\n"<<std::endl;
    }

    ++dtc1;
    dtc1();
    dtc1++;
    dtc1();

    std::cout<<dtc1;

    DTC dtc3;
    dtc3 = dtc1;

    dtc3();

    if(dtc1 > dtc2){
        std::cout<<"dtc1 Severity is higher than dtc2\n"<<std::endl;
    }else{
        std::cout<<"dtc2 Severity is higher than dtc1\n"<<std::endl;
    }

    std::cout<<"dtc1 code is: "<<dtc1["code"]<<std::endl;

    if(!dtc2){
        std::cout<<"dtc2 active status is inactive\n"<<std::endl;
    }else{
         std::cout<<"dtc2 active status is active\n"<<std::endl;
    }

    return 0;
}