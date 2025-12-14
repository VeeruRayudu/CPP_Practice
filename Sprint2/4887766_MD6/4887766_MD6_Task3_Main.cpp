#include <iostream>

int main(){
    double fuelCalibration = 1.05;
    std::string vehicleMode = "Eco";
    bool isEngineOn = true;

    auto calculateFuelEfficiency = [fuelCalibration](double fuelRate){
        return fuelRate*fuelCalibration;
    };

    vehicleMode = "Sport";
    auto reportMode = [&vehicleMode](){
        return "current mode: "+vehicleMode;
    };

    isEngineOn = false;
    auto engineStatusReport = [=](){
        return std::string("Engine is ") + (isEngineOn ? "ON" : "OFF");
    };

    auto liveStatusReport = [&](){
        return "Live Mode: " + vehicleMode + ", Engine:" + (isEngineOn ? "ON" : "OFF");
    };

    fuelCalibration = 0.95;
    vehicleMode = "Comfort";
    auto customReport = [fuelCalibration, &vehicleMode](double fuelRate){
        return "Mode: " + vehicleMode + ", Adjusted fuel rate: " + std::to_string(fuelRate * fuelCalibration);
    };

    std::cout<<calculateFuelEfficiency(8.5)<<std::endl;
    std::cout<<reportMode()<<std::endl;
    std::cout<<engineStatusReport()<<std::endl;
    std::cout<<liveStatusReport()<<std::endl;
    std::cout<<customReport(7.2)<<std::endl;

    return 0;
}