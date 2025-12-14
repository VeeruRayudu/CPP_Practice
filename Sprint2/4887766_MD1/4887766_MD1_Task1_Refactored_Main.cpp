#include "4887766_MD1_Task1_Refactored_Vehicle.h"
#include <array>

int main() {
    Car car("CAR1234", 2020, 4);
    Truck truck("TRK5678", 2018, 3.5);
    ElectricCar eCar("ELE9012", 2022, 92.5);

    std::array<Vehicle*, 3> vehicles = { &car, &truck, &eCar };

    for (const auto& vehicle : vehicles) {
        std::cout << "\n-------------------------------------------------\n";
        vehicle->displayInfo();
        vehicle->runDiagnostics();
    }

    std::cout << std::endl;
    return 0;
}