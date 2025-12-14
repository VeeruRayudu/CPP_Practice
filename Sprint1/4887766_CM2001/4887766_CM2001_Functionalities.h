#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "4887766_CM2001_ElectricVehicle.h"
#include <stdexcept>

void addVehicle(ElectricVehicle*& vehicles, int& count, int size, const ElectricVehicle& eV);
int findMaxTorque(ElectricVehicle*& vehicles, int count, const std::string& id);
void displayBatteryDischargePercentage(ElectricVehicle*& vehicles, int count);

#endif