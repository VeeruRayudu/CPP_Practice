#include<iostream>
#include<string>
#include "4887766_MD1_Task1_FleetVehicle.h"

//default constructor
FleetVehicle::FleetVehicle(){
    m_vehicleID = 0;
    m_fuelLevel = 50.0;
    m_distanceTravelled = 0.0;
    m_status = 'A';
    m_isAvailable = true;
    m_driverName = "Unassigned";
}

//parameterized constructor
FleetVehicle::FleetVehicle(int vehicleID_, float fuelLevel_, double distanceTravelled_, char status_, bool isAvailable_, std::string driverName_){
    this->m_vehicleID = vehicleID_;
    this->m_fuelLevel = fuelLevel_;
    this->m_distanceTravelled = distanceTravelled_;
    this->m_status = status_;
    this->m_isAvailable = isAvailable_;
    this->m_driverName = driverName_;
}

//destructor
FleetVehicle::~FleetVehicle(){
    std::cout<<"Destructor called for Vehicle ID: "<<m_vehicleID<<std::endl;
}

//getters
int FleetVehicle::getVehicleID(){ return m_vehicleID; }
float FleetVehicle::getFuelLevel(){ return m_fuelLevel; }
double FleetVehicle::getDistanceTravelled(){ return m_distanceTravelled; }
char FleetVehicle::getStatus(){ return m_status; }
bool FleetVehicle::getIsAvailable(){ return m_isAvailable; }
std::string FleetVehicle::getDriverName(){ return m_driverName; }

//setters
void FleetVehicle::setVehicleID(int vehicleID_){ m_vehicleID = vehicleID_; }
void FleetVehicle::setFuelLevel(float fuelLevel_){ m_fuelLevel=fuelLevel_; }
void FleetVehicle::setDistanceTravelled(double distanceTravelled_){ m_distanceTravelled = distanceTravelled_; }
void FleetVehicle::setStatus(char status_){ m_status = status_; }
void FleetVehicle::setIsAvailable(bool isAvailable_){ m_isAvailable = isAvailable_; }
void FleetVehicle::setDriverName(std::string driverName_){ m_driverName = driverName_; }

void FleetVehicle::updateStatus(){
    if(m_fuelLevel < 10.0 || !m_isAvailable){
        m_status = 'I';
    }else{
        m_status = 'A';
    }
}

//display vehicle details
void FleetVehicle::displayInfo(){
    std::cout<<"Vehicle ID: "<<m_vehicleID<<", Fuel Level: "<<m_fuelLevel<<", DistanceTravelled: "<<m_distanceTravelled<<", Status: "<<m_status<<", Is Available: "<<m_isAvailable<<", Driver Name: "<<m_driverName<<std::endl;
}

void assignDriver(FleetVehicle &vehicle, std::string name){
    vehicle.FleetVehicle::setDriverName(name);
    std::cout<<"Driver "<<vehicle.getDriverName()<<" has been assigned to vehicle ID "<<vehicle.getVehicleID()<<std::endl;
}

void refuelVehicle(FleetVehicle &vehicle, float fuelAmount){
    if(fuelAmount <= 0){
        std::cout<<"fuel level should be greater than zero"<<std::endl;
    }
    float newLevel = vehicle.getFuelLevel() + fuelAmount;
    vehicle.FleetVehicle::setFuelLevel(newLevel);
    std::cout<<"Vehicle ID: "<<vehicle.getVehicleID()<<" refueled by "<<newLevel<<std::endl;
}

