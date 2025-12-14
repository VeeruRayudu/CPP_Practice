#include <iostream>
#include <string>
#include <functional>

int main() {
    double fuelCalibration = 1.05;
    std::string vehicleMode = "Eco";
    bool isEngineOn = true;

    // Capture by value: fuelCalibration
    auto calculateFuelEfficiency = [fuelCalibration](double fuelRate) {
        return fuelRate * fuelCalibration;
    };

    vehicleMode = "Sport";
    // Capture by reference: vehicleMode
    auto reportMode = [&vehicleMode]() {
        return "Current mode: " + vehicleMode;
    };

    isEngineOn = false;
    // Capture all by value
    auto engineStatusReport = [=]() {
        return "Engine is " + std::string(isEngineOn ? "ON" : "OFF");
    };

    // Capture all by reference
    auto liveStatusReport = [&]() {
        return "Live Mode: " + vehicleMode + ", Engine: " + (isEngineOn ? "ON" : "OFF");
    };

    fuelCalibration = 0.95;
    vehicleMode = "Comfort";
    // Mixed capture: fuelCalibration by value, vehicleMode by reference
    auto customReport = [fuelCalibration, &vehicleMode](double fuelRate) {
        return "Mode: " + vehicleMode + ", Adjusted fuel rate: " + std::to_string(fuelRate * fuelCalibration);
    };

    // Output reports
    std::cout << "Fuel Efficiency: " << calculateFuelEfficiency(8.5) << "\n";
    std::cout << reportMode() << "\n";
    std::cout << engineStatusReport() << "\n";
    std::cout << liveStatusReport() << "\n";
    std::cout << customReport(7.2) << "\n";

    return 0;
}