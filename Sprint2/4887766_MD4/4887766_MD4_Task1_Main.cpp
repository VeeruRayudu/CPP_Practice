#include "4887766_MD4_Task1_Vehicle.h"

int main()
{
    Vehicle vehicles[3] = {
        {101, "Sedan", 85.0, 12.5, Status::OK},
        {102, "SUV", 95.0, 11.8, Status::WARN},
        {103, "Coupe", 105.0, 12.0, Status::FAIL}};

    std::cout << "\n------------Initial Details-----------------\n";
    for (auto &v : vehicles)
    {
        v.print();
    }

    // updating temperature and voltage
    vehicles[0].updateTemperature(88.0);
    vehicles[1].updateVoltage(12.0);

    // setting status
    vehicles[0].setStatus(Status::OK);
    vehicles[1].setStatus(Status::FAIL);
    vehicles[2].setStatus(Status::WARN);

    std::cout << "\n------------Details after update-----------------\n";
    for (auto &v : vehicles)
    {
        v.print();
    }

    // logging vehicle details
    std::cout << "\n------------Logger Functions-----------------\n";
    logVehicleByValue(vehicles[0]);
    logVehicleByRef(vehicles[1]);
    logVehicleByRRef(Vehicle(104, "Fortuner", 100.0, 12.0, Status::OK));
    logVehicleByPtr(&vehicles[2]);

    // filter function using lambda
    auto filter = [](const Vehicle &v) -> bool
    {
        return (v.getTemperature() > 90.0 || v.getVoltage() < 12.0);
    };

    // storing filter results and printing them
    Vehicle filtered[3];
    int count = 0;
    for (auto &v : vehicles)
    {
        if (filter(v))
        {
            filtered[count++] = v;
        }
    }

    std::cout << "\n------------Filtered Vehicles-----------------\n";
    for (int i = 0; i < count; i++)
    {
        filtered[i].print();
    }

    return 0;
}