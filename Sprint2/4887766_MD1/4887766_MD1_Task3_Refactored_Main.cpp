#include "4887766_MD1_Task3_Vehicle.h"
#include <array>
#include <iostream>

int main() {
    Vehicle v1;
    Vehicle v2("Sedan", 2022);
    Vehicle v3("SUV", 2023);

    std::array<Vehicle*, 3> vehicles = { &v1, &v2, &v3 };

    std::cout << "\nVehicle Status Report:\n";

    for (const auto& v : vehicles) {
        std::cout << "\n----------------------------------------\n";
        v->show();
    }

    std::cout << std::endl;
    return 0;
}