#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <cstring>
#include <stdexcept>

enum VehicleType {COMMERCIAL, PASSENGER};

class Vehicle{
    private:
    int* m_testScores;
    unsigned int m_numberOfTestRuns;
    char* m_vehicleID;
    VehicleType m_type;

    public:
    Vehicle();
    Vehicle(unsigned int n);
    Vehicle(const Vehicle& other);
    ~Vehicle();
    bool operator==(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    int operator[](int index);
    friend std::ostream& operator<<(std::ostream&, const Vehicle&);
    friend std::istream& operator>>(std::istream&, Vehicle&);
    double averageScore() const;
    VehicleType getVehicleType() const;
};

void findMinAvgScore(Vehicle vArr[], int size);
void showVehicles(Vehicle vArr[], int size, VehicleType type);

#endif