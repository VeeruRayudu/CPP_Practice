#include "4887766_CM2001_ElectricVehicle.h"

//constructor initialization
ElectricVehicle::ElectricVehicle(std::string vehicleID_, std::string vehicleModel_, float batteryCapacity_, ElectricMotor m): m_vehicleID(vehicleID_), m_vehicleModel(vehicleModel_), m_batteryCapacity(batteryCapacity_), electricMotor(m) {};

//getters
std::string ElectricVehicle::getVehicleID() const { return m_vehicleID; }
std::string ElectricVehicle::getVehicleModel() const { return m_vehicleModel; }
float ElectricVehicle::getBatteryCapacity() const{ return m_batteryCapacity; }

//setters
void ElectricVehicle::setVehicleID(std::string vehicleID_) { m_vehicleID = vehicleID_; }
void ElectricVehicle::setVehicleModel(std::string vehicleModel_) { m_vehicleModel = vehicleModel_; }
void ElectricVehicle::setBatteryCapacity(float batteryCapacity_) { m_batteryCapacity = batteryCapacity_; }

//<< overload
std::ostream& operator<<(std::ostream& os, const ElectricVehicle& eV){
    os<<"Vehicle ID: "<<eV.m_vehicleID<<"\n"
      <<"Vehicle Model: "<<eV.m_vehicleModel<<"\n"
      <<"Battery Capacity: "<<eV.m_batteryCapacity<<"\n";
    return os;
}

float ElectricVehicle::operator+(const ElectricVehicle& other){
    return (this->getBatteryCapacity() + other.getBatteryCapacity());   
}