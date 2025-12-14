#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <string>

// Vehicle class encapsulating vehicle data and behavior
class Vehicle {
private:
    std::string id_;
    float mileage_;
    bool isCommercial_;

public:
    Vehicle(std::string id, float mileage, bool isCommercial)
        : id_(std::move(id)), mileage_(mileage), isCommercial_(isCommercial) {}

    void display() const {
        std::cout << "ID: " << id_
                  << ", Mileage: " << mileage_
                  << ", Commercial: " << (isCommercial_ ? "Yes" : "No")
                  << std::endl;
    }

    float getMileage() const { return mileage_; }
    bool isCommercial() const { return isCommercial_; }
};

// Type aliases for clarity
using VehiclePtr = std::shared_ptr<Vehicle>;
using MaintenanceRule = std::function<void(const Vehicle&)>;

// Utility to apply all rules to all vehicles
void applyMaintenanceRules(const std::vector<VehiclePtr>& vehicles,
                           const std::vector<MaintenanceRule>& rules) {
    for (const auto& vehicle : vehicles) {
        for (const auto& rule : rules) {
            rule(*vehicle);
        }
    }
}

int main() {
    // Create vehicles
    std::vector<VehiclePtr> vehicles = {
        std::make_shared<Vehicle>("MH12AB1234", 16000, false),
        std::make_shared<Vehicle>("MH14XY5678", 9500, true),
        std::make_shared<Vehicle>("MH01EV9999", 10500, true)
    };

    // Define maintenance rules
    std::vector<MaintenanceRule> rules = {
        [](const Vehicle& v) {
            if (v.getMileage() > 15000) {
                v.display();
                std::cout << "Rule 1 triggered\n";
            }
        },
        [](const Vehicle& v) {
            if (v.isCommercial() && v.getMileage() > 10000) {
                v.display();
                std::cout << "Rule 2 triggered\n";
            }
        }
    };

    // Apply rules
    applyMaintenanceRules(vehicles, rules);

    return 0;
}