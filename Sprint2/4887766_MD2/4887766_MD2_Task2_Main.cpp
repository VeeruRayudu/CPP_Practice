#include "4887766_MD2_Task2_Owner.h"

int main(){
    //object creation
    VehicleSummary* v1 = new VehicleSummary("VIN-A");
    VehicleSummary* v2 = new VehicleSummary("VIN-B");

    Owner owner("Rita");
    
    //adding vehicle to owner vector
    owner.addVehicle(v1);
    std::cout<< ownerReport(owner) <<std::endl;
    
    owner.addVehicle(v2);
    std::cout<< ownerReport(owner) <<std::endl;

    //displaying owner's vehicles info
    for(auto& str : owner.listVehicles()){
        std::cout<<str<<std::endl;
    }

    return 0;
}