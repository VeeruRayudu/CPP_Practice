#include <iostream>
#include <string>
#include <vector>
#include "4887766_MD1_Task1_Refactored_FleetVehicle.h"

void displayMenu() {
    std::cout << "\n------------- Fleet Monitoring System ------------------\n";
    std::cout << "1. Add Vehicle Details\n";
    std::cout << "2. Assign Driver\n";
    std::cout << "3. Refuel Vehicle\n";
    std::cout << "4. Update Status\n";
    std::cout << "5. Display Vehicle Information\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

FleetVehicle* findVehicleByID(std::vector<FleetVehicle>& fleet, int id) {
    for (auto& vehicle : fleet) {
        if (vehicle.getVehicleID() == id) {
            return &vehicle;
        }
    }
    return nullptr;
}

int main() {
    std::vector<FleetVehicle> fleet = {
        {101, 45.5f, 120.0, 'A', true, "Raj"},
        {102, 8.0f, 300.0, 'A', true, "Priya"},
        {}
    };

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                float fuel;
                double dist;
                char status;
                bool isAvail;
                std::string driverName;

                std::cout << "Enter Vehicle ID: "; std::cin >> id;
                std::cout << "Enter Fuel Level: "; std::cin >> fuel;
                std::cout << "Enter Distance Travelled: "; std::cin >> dist;
                std::cout << "Enter Status (A for Active / I for Inactive): "; std::cin >> status;
                std::cout << "Is Available (1 for Yes / 0 for No): "; std::cin >> isAvail;
                std::cin.ignore();
                std::cout << "Enter Driver Name: "; std::getline(std::cin, driverName);

                fleet.emplace_back(id, fuel, dist, status, isAvail, driverName);
                break;
            }

            case 2: {
                int id;
                std::string driverName;
                std::cout << "Enter Vehicle ID: "; std::cin >> id;
                std::cin.ignore();

                FleetVehicle* vehicle = findVehicleByID(fleet, id);
                if (vehicle) {
                    std::cout << "Enter Driver Name: "; std::getline(std::cin, driverName);
                    assignDriver(*vehicle, driverName);
                } else {
                    std::cout << "Vehicle not found\n";
                }
                break;
            }

            case 3: {
                int id;
                float fuelAmount;
                std::cout << "Enter Vehicle ID: "; std::cin >> id;

                FleetVehicle* vehicle = findVehicleByID(fleet, id);
                if (vehicle) {
                    std::cout << "Enter Fuel Amount: "; std::cin >> fuelAmount;
                    refuelVehicle(*vehicle, fuelAmount);
                } else {
                    std::cout << "Vehicle not found\n";
                }
                break;
            }

            case 4: {
                int id;
                std::cout << "Enter Vehicle ID: "; std::cin >> id;

                FleetVehicle* vehicle = findVehicleByID(fleet, id);
                if (vehicle) {
                    vehicle->updateStatus();
                    std::cout << "Status updated for Vehicle ID: " << id << std::endl;
                } else {
                    std::cout << "Vehicle not found\n";
                }
                break;
            }

            case 5: {
                int id;
                std::cout << "Enter Vehicle ID: "; std::cin >> id;

                FleetVehicle* vehicle = findVehicleByID(fleet, id);
                if (vehicle) {
                    vehicle->displayInfo();
                } else {
                    std::cout << "Vehicle not found\n";
                }
                break;
            }

            case 6:
                std::cout << "Exiting the program\n";
                break;

            default:
                std::cout << "Invalid choice!\n";
                break;
        }

    } while (choice != 6);

    return 0;
}