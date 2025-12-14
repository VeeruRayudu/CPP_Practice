#include "4887766_CM2001_Functionalities.h"

int main(){
    //TC1
    int size;
    std::cout<<"Enter total number of vehicles (>=4): ";
    std::cin>>size;
    std::cout<<"\n---------------------TC1------------------\n";
    ElectricVehicle* vehicles = new ElectricVehicle[size];
    int count = 0;
    std::cout<<"Dynamic array created."<<"\n";

    //TC2
    std::cout<<"\n---------------------TC2------------------\n";
    ElectricVehicle ev1("v1", "Model1", 60.0, ElectricMotor(100.0, 200));
    ElectricVehicle ev2("v2", "Model2", 70.0, ElectricMotor(150.0, 300));
    addVehicle(vehicles, count, size, ev1);
    addVehicle(vehicles, count, size, ev2);

    //TC3
    std::cout<<"\n---------------------TC3------------------\n";
    std::cout<<"Battery Capacity Sum: "<<ev1+ev2<<"\n";

    //TC4
    std::cout<<"\n---------------------TC4------------------\n";
    std::cout<<"Max Torque for ID v2: "<<findMaxTorque(vehicles, size, "v2")<<"\n";

    //TC5
    std::cout<<"\n---------------------TC5------------------\n";
    try{
    std::cout<<"Max Torque for ID v2: "<<findMaxTorque(vehicles, size, "v8")<<"\n";
    } catch(const std::exception& e){
        std::cout<<e.what()<<"\n";
    }

    //TC6
    std::cout<<"\n---------------------TC6------------------\n";
    displayBatteryDischargePercentage(vehicles, count);

    delete[] vehicles;

    return 0;

}