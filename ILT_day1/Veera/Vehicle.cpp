#include<iostream>
#include "Vehicle.h"

Vehicle::Vehicle(): m_id(0), m_isElectric(false), m_mileage(12.5), m_vehicleType(VehicleType::CAR){};

Vehicle::Vehicle(int id_, bool isElectric_, double mileage_, VehicleType vehicleType_): m_id(id_), m_isElectric(isElectric_), m_mileage(mileage_), m_vehicleType(vehicleType_) {};

Vehicle::Vehicle(Vehicle& other){
    m_id = other.m_id;
    m_isElectric = other.m_isElectric;
    m_mileage = other.m_mileage;
    m_vehicleType = other.m_vehicleType;
}

//getters
