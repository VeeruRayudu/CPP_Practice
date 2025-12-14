#ifndef INDIVIDUALTRIP_H
#define INDIVIDUALTRIP_H
#include <iostream>
#include <string>
#include "4887766_CM1001_Trip.h"

class IndividualTrip: public Trip{
    private:
    int m_individualTripDuration;

    public:
    IndividualTrip();

    //getter
    int getIndividualTripDuration() const;

    //setter
    void setIndividualTripDuration(int duration_);

    float calculateFare();
    float calculateFare(float surcharge);
    bool isTripAsPerStandard();
};

#endif