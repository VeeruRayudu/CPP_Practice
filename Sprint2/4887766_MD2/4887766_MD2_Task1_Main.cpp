#include "4887766_MD2_Task1_Vehicle.h"

int main(){
    //vector containing pointers
    std::vector<Vehicle*> vehicles;

    //adding vehicle ptrs
    vehicles.emplace_back(new Car("1HGCM82633A004352", 5));
    vehicles.emplace_back(nullptr);
    vehicles.emplace_back(new Truck("3H7CM82633A009999", 12.5));

    //iterating vector 
    for(auto& v : vehicles){
        printVehicleInfo(v);
    }

    return 0;
}