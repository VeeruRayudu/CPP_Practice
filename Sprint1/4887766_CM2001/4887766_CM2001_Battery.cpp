#include "4887766_CM2001_Battery.h"

// parameterized constructor initialization
Battery::Battery(int batteryID_, std::string batteryType_, std::string manufacturer_, double capacity_, double voltage_) : m_batteryID(batteryID_), m_batteryType(batteryType_), m_manufacturer(manufacturer_), m_capacity(capacity_), m_voltage(voltage_) {};

// getters
int Battery::getBatterID() { return m_batteryID; }
std::string Battery::getBatteryType() { return m_batteryType; }
std::string Battery::getManufacturer() { return m_manufacturer; }
double Battery::getCapacity() { return m_capacity; }
double Battery::getVoltage() { return m_voltage; }

// setters
void Battery::setBatteryID(int batteryID_) { m_batteryID = batteryID_; }
void Battery::setBatteryType(std::string batteryType_) { m_batteryType = batteryType_; }
void Battery::setManufacturer(std::string manufacturer_) { m_manufacturer = manufacturer_; }
void Battery::setCapacity(double capacity_) { m_capacity = capacity_; }
void Battery::setVoltage(double voltage_) { m_voltage = voltage_; }

// overload << to display object details
std::ostream &operator<<(std::ostream &os, Battery &battery)
{
    os << "Battery ID: " << battery.m_batteryID << "\n"
       << "Battery Type: " << battery.m_batteryType << "\n"
       << "Battery Manufacturer: " << battery.m_manufacturer << "\n"
       << "Capacity: " << battery.m_capacity << "\n"
       << "Voltage: " << battery.m_voltage << "\n";

    return os;
}

//string comparision function
bool equalsIgnoreCase(std::string a, std::string b)
{
    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    std::transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a == b;
}

// search function to search for batteries of same manufacturer
void searchBatteriesByManufacturer(Battery *batteries, int count, std::string manufacturer)
{
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (equalsIgnoreCase(batteries[i].getManufacturer(), manufacturer))
        {
            std::cout << batteries[i];
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "Battery not found for " << manufacturer << "\n";
    }
}

//display all battery details
void showAllBatteries(Battery *batteries, int count)
{
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            std::cout << batteries[i];
            std::cout<<"\n";
        }
    }
    else
    {
        std::cout << "No battery records found!" << "\n";
    }
}