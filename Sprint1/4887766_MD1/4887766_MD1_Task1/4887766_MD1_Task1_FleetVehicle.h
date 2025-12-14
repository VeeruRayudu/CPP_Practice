#ifndef FLEETVEHICLE_H
#define FLEETVEHICLE_H
#include<string>

class FleetVehicle{
    private:
    int m_vehicleID;
    float m_fuelLevel;
    double m_distanceTravelled;
    char m_status;
    bool m_isAvailable;
    std::string m_driverName;

    public:
    //default constructor
    FleetVehicle();
    //parameterized constructor
    FleetVehicle(int vehicleID_, float fuelLevel_, double distanceTravelled_, char status_, bool isAvailable_, std::string driverName_);

    //destructor
    ~FleetVehicle();

    //getters
    int getVehicleID(){ return m_vehicleID; }
    float getFuelLevel(){ return m_fuelLevel; }
    double getDistanceTravelled(){ return m_distanceTravelled; }
    char getStatus(){ return m_status; }
    bool getIsAvailable(){ return m_isAvailable; }
    std::string getDriverName(){ return m_driverName; }

    //setters
    void setVehicleID(int vehicleID_);
    void setFuelLevel(float fuelLevel_);
    void setDistanceTravelled(double distanceTravelled_);
    void setStatus(char status_);
    void setIsAvailable(bool isAvailable_);
    void setDriverName(std::string driverName_);

    void updateStatus();
    void displayInfo();
};

//gloabal functions
void assignDriver(FleetVehicle &vehicle, std::string name);
void refuelVehicle(FleetVehicle &vehicle, float fuelAmount);

#endif