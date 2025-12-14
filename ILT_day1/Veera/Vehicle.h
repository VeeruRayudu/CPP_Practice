#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

enum VehicleType { CAR, TRUCK, MOTORCYCLE};

class Vehicle{
    private:
    int m_id;
    bool m_isElectric;
    double m_mileage;
    VehicleType m_vehicleType;

    public:
    Vehicle();
    Vehicle(int id_, bool isElectric_, double mileage_, VehicleType m_vehicleType);
    Vehicle(Vehicle& other);

    //getters
    int getId(){ return m_id;}
    bool getIsElectric() { return m_isElectric;}
    double getMileage() { return m_mileage;}
    VehicleType getVehicleType(){ return m_vehicleType;}

    //setters
    void setId(int id_){ m_id = id_;}
    void setIsElectric(bool isElectric_){ m_isElectric = isElectric_;}
    void setMileage(double mileage_) { m_mileage = mileage_;}
    void setVehicleType(VehicleType vehicleType_) { m_vehicleType = vehicleType_;}

    Vehicle operator+(const Vehicle& other);
    friend std::ostream& operator<<(const std::ostream& os, const Vehicle& other);
};
#endif