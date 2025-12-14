#include "4887766_MD2_Task3_Fleet.h"

int main(){
    //created garage
    Garage garage("Plant-A");

    //created vehicle and added to garage
    FleetVehicle v1("F123", 150);
    v1.setState(VehicleState::PARKED);
    garage.addVehicle(v1);

    //added garage to fleet
    Fleet fleet;
    fleet.addGarage(std::move(garage));

    std::cout<<"\nTotal Vehicles: "<<fleet.totalVehicles()<<std::endl;
    
    FleetVehicle v2("F200", 200);
    std::cout<<v2.status()<<std::endl;

    v2.setState(VehicleState::INTRANSIT);
    std::cout<<v2.status()<<std::endl;
}