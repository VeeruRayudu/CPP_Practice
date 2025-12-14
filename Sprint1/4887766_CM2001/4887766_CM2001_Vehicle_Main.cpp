#include "4887766_CM2001_Vehicle.h"

int main(){
    //Vehicle object creation
    Vehicle v1("V123", "Gasoline", 25.0);

    //tracking fuel consumption
    v1.trackFuelConsumption(10, 250);
    std::cout<<"Vehicle details after tracking fuel consumption: \n";
    v1.displayVehicleInfo();

    //fuel economy calculation
    std::cout<<"Fuel Economy: "<<v1.calculateFuelEconomy()<<"\n";

    //updating avg fuel price
    v1.updateAverageFuelPrice(2.75);

    //calculating total fuel cost
    std::cout<<"Total fuel cost for distance(500): "<<v1.calculateTotalFuelCost(500)<<"\n";

    return 0;
}

