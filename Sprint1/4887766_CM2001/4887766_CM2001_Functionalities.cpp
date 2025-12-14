#include "4887766_CM2001_ElectricVehicle.h"
#include <stdexcept>

void addVehicle(ElectricVehicle*& vehicles, int& count, int size, const ElectricVehicle& eV){
    if(count >= size){
        std::cout<<"Array full!"<<"\n";
    }
    if(eV.getBatteryCapacity() > 80.0){
        std::cout<<"Battery capacity cannot be greater than 80!"<<"\n";
    }
    vehicles[count++] = eV;
    std::cout<<"Vehicle added successfully."<<"\n";
}

int findMaxTorque(ElectricVehicle*& vehicles, int count, const std::string& id){
    for(int i=0; i<count; i++){
        if(vehicles[i].getVehicleID() == id){
            if(vehicles[i].getBatteryCapacity() >= 30.5){
                return vehicles[i].getMotor().getMaxTorque();
            }
        }
    }
    throw std::runtime_error("Invalid Vehicle ID!");
}

void displayBatteryDischargePercentage(ElectricVehicle*& vehicles, int count){
    std::cout<<"Battery Discharge Rates: "<<"\n";
    for(int i=0; i<count; i++){
        std::cout<<"Vehicle ID: "<<vehicles[i].getVehicleID()<<", Battery Discharge Rate: "<<(vehicles[i].getBatteryCapacity() * 0.10f)<<"%\n";   
    }
}
