#ifndef SHAREDTRIP_H
#define SHAREDTRIP_H
#include <iostream>
#include <string>
#include "4887766_CM1001_Trip.h"

class SharedTrip: public Trip{
    private:
    int m_sharedTripPassengers;

    public:
    SharedTrip();

    //getter
    int getSharedTripPassengers() const;

    //setter
    void setSharedTripPassengers(int passengers_);

    float calculateFare();
    bool isTripAsPerStandard();
};

#endif