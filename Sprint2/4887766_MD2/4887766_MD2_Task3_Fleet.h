#ifndef FLEET_H
#define FLEET_H
#include "4887766_MD2_Task3_Garage.h"
#include <iostream>
#include <vector>

class Fleet{
    private:
    std::vector<Garage> garages;

    public:
    //defaulted constructor
    Fleet() = default;

    void addGarage(Garage&& g) noexcept{
        garages.emplace_back(std::move(g));
    }

    int totalVehicles(){
        int sum = 0;
        for(auto& g : garages){
            sum += g.getVehicleCount();
        }

        return sum;
    }
};

#endif