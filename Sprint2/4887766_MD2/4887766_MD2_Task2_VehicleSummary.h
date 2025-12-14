#ifndef VEHICLE_SUMMARY_H
#define VEHICLE_SUMMARY_H
#include <iostream>
#include <sstream>

using VIN = std::string;

class VehicleSummary{
    public:
    VIN m_vin;

    //constructor
    VehicleSummary(VIN vin_);

    std::string info() const noexcept;
};

#endif