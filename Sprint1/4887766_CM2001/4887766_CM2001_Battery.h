#ifndef BATTERY_H
#define BATTERY_H
#include <iostream>
#include <string>
#include <algorithm>

class Battery{
    private:
    int m_batteryID;
    std::string m_batteryType;
    std::string m_manufacturer;
    double m_capacity;
    double m_voltage;

    public:
    //parameterized constructor
    Battery(int batteryID_, std::string batteryType_, std::string manufacturer_, double capacity_, double voltage_);

    //getters
    int getBatterID();
    std::string getBatteryType();
    std::string getManufacturer();
    double getCapacity();
    double getVoltage();

    //setters
    void setBatteryID(int batteryID_);
    void setBatteryType(std::string batteryType_);
    void setManufacturer(std::string manufacturer_);
    void setCapacity(double capacity_);
    void setVoltage(double voltage_);

    //overload operator
    friend std::ostream& operator<<(std::ostream& os, Battery& battery);
};

//global functions
void searchBatteriesByManufacturer(Battery* batteries, int count, std::string manufacturer);
void showAllBatteries(Battery* batteries, int count);

#endif