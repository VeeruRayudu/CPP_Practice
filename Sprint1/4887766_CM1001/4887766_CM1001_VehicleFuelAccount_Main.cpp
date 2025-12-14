#include <iostream>
#include "4887766_CM1001_VehicleFuelAccount.h"

int main(){
    VehicleFuelAccount* vPtr1 = new VehicleFuelAccount(2000.00);
    VehicleFuelAccount* vPtr2 = new VehicleFuelAccount(3000.00);
    VehicleFuelAccount* vPtr3 = new VehicleFuelAccount(2500.00);
    VehicleFuelAccount* arr[3] = {vPtr1, vPtr2, vPtr3};

    //TC1
    std::cout<<"\n-------------------TC1-------------------\n";
    VehicleFuelAccount::modifyEfficiencyRate(3.0);
    applyBonusToFleet(arr, 3);
    std::cout<<"---Updated Balances---\n";
    for(int i=0; i<3; i++){
        arr[i]->display();
    }

    //TC2
    std::cout<<"\n-------------------TC2-------------------\n";
    std::cout<<"Total Fleet Fuel: "<<getTotalFleetFuel(arr, 3)<<" liters"<<"\n";

    //TC3
    std::cout<<"\n-------------------TC3-------------------\n";
    VehicleFuelAccount::modifyEfficiencyRate(4.0);
    applyBonusToFleet(arr, 3);
    std::cout<<"---Updated Balances---\n";
    for(int i=0; i<3; i++){
        arr[i]->display();
    }

    //TC4
    std::cout<<"\n-------------------TC4-------------------\n";
    std::cout<<"Total Fleet Fuel: "<<getTotalFleetFuel(arr, 3)<<" liters"<<"\n";

    for(int i=0;i<3;i++){
        delete arr[i];
        arr[i] = nullptr;
    }

    return 0;
}