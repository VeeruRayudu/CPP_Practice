#include "4887766_MD4_Task1_Refactored_Vehicle.h"
#include <array>

int main() {
    std::array<Vehicle, 3> vehicles = {
        Vehicle{101, "Sedan", 85.0, 12.5, Status::OK},
        Vehicle{102, "SUV", 95.0, 11.8, Status::WARN},
        Vehicle{103, "Coupe", 105.0, 12.0, Status::FAIL}
    };

    std::cout << "\n------------Initial Details-----------------\n";
    for (const auto& v : vehicles) {
        v.print();
    }

    vehicles[0].updateTemperature(88.0);
    vehicles[1].updateVoltage(12.0);

    vehicles[0].setStatus(Status::OK);
    vehicles[1].setStatus(Status::FAIL);
    vehicles[2].setStatus(Status::WARN);

    std::cout << "\n------------Details after update-----------------\n";
    for (const auto& v : vehicles) {
        v.print();
    }

    std::cout << "\n------------Logger Functions-----------------\n";
    logVehicleByValue(vehicles[0]);
    logVehicleByRef(vehicles[1]);
    logVehicleByRRef(Vehicle{104, "Fortuner", 100.0, 12.0, Status::OK});
    logVehicleByPtr(&vehicles[2]);

    auto filter = [](const Vehicle& v) {
        return v.getTemperature() > 90.0 || v.getVoltage() < 12.0;
    };

    std::array<Vehicle, 3> filtered{};
    int count = 0;
    for (const auto& v : vehicles) {
        if (filter(v)) {
            filtered[count++] = v;
        }
    }

    std::cout << "\n------------Filtered Vehicles-----------------\n";
    for (int i = 0; i < count; ++i) {
        filtered[i].print();
    }

    return 0;
}