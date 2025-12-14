#include "4887766_CM1001_Vehicle.h"

int main(){
    //TC1
    std::cout<<"\n-------------------TC1--------------------\n";
    Vehicle vehicles[3];
    for(int i=0; i<3; i++){
        std::cout<<"Enter details for Vehicle "<<i+1<<": \n";
        std::cin>>vehicles[i];
    }
    for(int i=0; i<3; i++){
        std::cout<<"All Vehicles:\n";
        std::cout<<vehicles[i];
    }

    Vehicle vehicleCopy = vehicles[1];

    //TC2
    std::cout<<"\n-------------------TC2--------------------\n";
    std::cout<<((vehicles[0] == vehicles[1])?"true":"false");

    //TC3
    std::cout<<"\n-------------------TC3--------------------\n";
    std::cout<<((vehicleCopy == vehicles[1])?"true":"false");

    //TC4
    std::cout<<"\n-------------------TC4--------------------\n";
    std::cout<<vehicles[2][1]<<"\n";

    //TC5
    std::cout<<"\n-------------------TC5--------------------\n";
    std::cout<<vehicles[0][4]<<"\n";

    //TC6
    std::cout<<"\n-------------------TC6--------------------\n";
    Vehicle vehicleAssignment;
    vehicleAssignment = vehicles[1];
    std::cout<<"Assignment operator Demonstration: "<<vehicleAssignment<<"\n";

    //TC7
    std::cout<<"\n-------------------TC7--------------------\n";
    std::cout<<"Copy constructor Demonstration: "<<vehicleCopy<<"\n";

    //TC8
    std::cout<<"\n-------------------TC8--------------------\n";
    findMinAvgScore(vehicles, 3);

    //TC9
    std::cout<<"\n-------------------TC9--------------------\n";
    showVehicles(vehicles, 3, VehicleType::COMMERCIAL);

    //TC10
    std::cout<<"\n-------------------TC10--------------------\n";
    showVehicles(vehicles, 3, VehicleType::PASSENGER);

    return 0;
}