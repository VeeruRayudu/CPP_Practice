#ifndef FLEETVEHICLE_H
#define FLEETVEHICLE_H

#include <string>

class FleetVehicle {
private:
    int vehicleID{};
    float fuelLevel{};
    double distanceTravelled{};
    char status{};
    bool isAvailable{};
    std::string driverName;

public:
    // Constructors
    FleetVehicle();  // Default
    FleetVehicle(int vehicleID, float fuelLevel, double distanceTravelled,
                 char status, bool isAvailable, const std::string& driverName);  // Parameterized

    // Destructor
    ~FleetVehicle();

    // Getters
    int getVehicleID() const;
    float getFuelLevel() const;
    double getDistanceTravelled() const;
    char getStatus() const;
    bool getIsAvailable() const;
    std::string getDriverName() const;

    // Setters
    void setVehicleID(int vehicleID);
    void setFuelLevel(float fuelLevel);
    void setDistanceTravelled(double distanceTravelled);
    void setStatus(char status);
    void setIsAvailable(bool isAvailable);
    void setDriverName(const std::string& driverName);

    // Utility methods
    void updateStatus();
    void displayInfo() const;
};

// Global functions
void assignDriver(FleetVehicle& vehicle, const std::string& name);
void refuelVehicle(FleetVehicle& vehicle, float fuelAmount);

#endif // FLEETVEHICLE_H