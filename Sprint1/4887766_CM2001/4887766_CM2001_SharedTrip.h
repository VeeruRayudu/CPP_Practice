#ifndef SHAREDTRIP_H
#define SHAREDTRIP_H
#include <iostream>
#include <string>
#include "4887766_CM2001_Trip.h"

class SharedTrip: public Trip{
    private:
    int m_sharedTripPassengers;

    public:
    SharedTrip(std::string tripID_ , int tripDistance_, int tripRating_ , RIDE tripVehicleType_, int sharedTripPassengers_ = 0);

    //getter
    int getSharedTripPassengers() const;

    //setter
    void setSharedTripPassengers(int passengers_);

    //<< overload to display details
    friend std::ostream& operator<<(std::ostream& os, const SharedTrip& sTrip);

    float calculateFare() override;

    bool isTripAsPerStandard();
};

#endif