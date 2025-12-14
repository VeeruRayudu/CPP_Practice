#include <iostream>
#include "4887766_CM1001_VehicleFuelAccount.h"

double VehicleFuelAccount::m_fleetEfficiencyRate = 0.0;

//constructor
VehicleFuelAccount::VehicleFuelAccount(double fuelBalance_): m_fuelBalance(fuelBalance_) {};

//destructor
VehicleFuelAccount::~VehicleFuelAccount(){};

void VehicleFuelAccount::calculateMonthlyBonus(){
    m_fuelBalance += (m_fuelBalance*(m_fleetEfficiencyRate/100.0))/12.0;
}

void VehicleFuelAccount::modifyEfficiencyRate(double newRate){
    m_fleetEfficiencyRate = newRate;
}

void VehicleFuelAccount::display(){
    std::cout<<m_fuelBalance<<"\n";
}

double VehicleFuelAccount::getFuelBalance() const {
    return m_fuelBalance;
}

void applyBonusToFleet(VehicleFuelAccount* arr[], int size){
    for(int i=0; i<size; i++){
        arr[i]->calculateMonthlyBonus();
    }
}

double getTotalFleetFuel(VehicleFuelAccount* arr[], int size){
    int totalFuel = 0;
    for(int i=0; i<size; i++){
        totalFuel += arr[i]->getFuelBalance();
    }
    return totalFuel;
}