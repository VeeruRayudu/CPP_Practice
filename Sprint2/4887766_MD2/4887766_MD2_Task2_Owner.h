#ifndef OWNER_H
#define OWNER_H
#include "4887766_MD2_Task2_VehicleSummary.h"
#include <iostream>
#include <vector>
#include <sstream>

class Owner{
    private:
    std::string m_name;
    std::vector<const VehicleSummary*> m_summaries;

    public:
    Owner() = delete;

    //constructor
    Owner(std::string name_);

    //deleted copy
    Owner(const Owner&) = delete;
    Owner& operator=(const Owner&) = delete;

    //move constructor
    Owner(Owner&&) = default;

    //move assignment
    Owner& operator=(Owner&&) = default;

    //add summary to vector
    void addVehicle(const VehicleSummary*);

    //listing vehicles
    std::vector<std::string> listVehicles() const noexcept;

    //getter
    std::string getName() const {return m_name;}

};

std::string ownerReport(const Owner&);

#endif