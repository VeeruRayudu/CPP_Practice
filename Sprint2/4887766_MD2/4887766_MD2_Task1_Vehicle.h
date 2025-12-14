#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

enum class VehicleType {UNKNOWN, CAR, TRUCK};

class Vehicle{
    protected:
    std::string m_vin;
    VehicleType m_type;

    public:
    Vehicle() = delete;       //default deleted

    //parameterized
    Vehicle(std::string vin_, VehicleType type_);

    //defaulted virtual destructor
    virtual ~Vehicle() = default;

    //pure virtual function
    virtual std::string description() const = 0;

    std::string getVIN() const noexcept;
    VehicleType getType() const noexcept;

};

class Car final: public Vehicle{
    private:
    int m_seatCount;

    public:
    Car() = delete;       //default deleted

    Car(std::string vin_, int seatCount);

    //virtual function override
    std::string description() const override;
};

class Truck final: public Vehicle{
    private:
    double m_payloadTons;

    public:
    Truck() = default;

    Truck(std::string vin_, double payload_);

    //virtual function override
    std::string description() const override;
};

void printVehicleInfo(const Vehicle* v);

#endif