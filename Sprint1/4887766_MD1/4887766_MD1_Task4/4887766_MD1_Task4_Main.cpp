#include<iostream>
#include<string>
#include<ctime>
#include "4887766_MD1_Task4_DTC.h"

void dynamicAllocationDemo(){
    DTC* dtcPtr = new DTC;

    dtcPtr->setCode("P0201");
    dtcPtr->setDescription("Injector 1 circuit malfunction");
    dtcPtr->setActive(true);
    dtcPtr->setSeverityLevel(Severity::WARN);

    dtcPtr->incrementOccurrence();
    dtcPtr->toggleMIL();
    
    dtcPtr->printDTCInfo();

    delete dtcPtr;
    dtcPtr = nullptr; //prevents dangling pointer which prevents accidental access to the freed memory
    
}

void leakDemo(){
    DTC* dtc1 = new DTC;
    DTC* dtc2 = new DTC;

    dtc1->setCode("P0302");
    dtc2->setCode("P0303");

    delete dtc1;
    //dtc2 is not deleted so memory leak occurs
}

void leakFix(){
    DTC* dtc1 = new DTC;
    DTC* dtc2 = new DTC;

    dtc1->setCode("P0302"); 
    dtc2->setCode("P0303"); 

    delete dtc1;
    delete dtc2; //deleted both objects
    
    dtc1 = nullptr;
    dtc2 = nullptr;  //now both prevents dangling pointer

}

void danglingPointerDemo(){
    DTC* dtcPtr = new DTC;
    dtcPtr->setCode("P0401");
    std::cout<<"inside dangling pointer";

    delete dtcPtr; 
    //dtcPtr->printDTCInfo(); :: unsafe:undefined behaviour

    dtcPtr = nullptr;

    if(dtcPtr){
        dtcPtr->printDTCInfo(); //this will not run
    }else{
        std::cout<<"Pointer is null";
    }
}

int main(){
    DTC dtc1;
    DTC dtc2("P0301", "Cylinder 1 Misfire Detected", true, 3, 1625247600, Severity::CRIT, true, false, true, "Engine", "ECU_01");
    
    dtc1.setCode("P0101");
    dtc1.setDescription("Mass Air flow sensor fault");

    dtc1.incrementOccurrence();
    dtc2.incrementOccurrence();

    dtc2.toggleMIL();
    dtc2.markConfirmed();

    std::cout<<"First Object: "<<"\n";
    dtc1.printDTCInfo();
    std::cout<<"second Object: "<<"\n";
    dtc2.printDTCInfo();

    dynamicAllocationDemo();
    leakDemo();
    leakFix();
    danglingPointerDemo();
    
}