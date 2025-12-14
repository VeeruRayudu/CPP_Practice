#ifndef INDIVIDUALTRIP_H
#define INDIVIDUALTRIP_H
#include "4887766_CM2001_Trip.h"

class IndividualTrip: public Trip{
    private:
    int m_individualTripDuration;

    public:
    //constructor
    IndividualTrip(std::string tripID_ , int tripDistance_, int tripRating_ , RIDE tripVehicleType_, int individualTripDuration_ = 0);

    //getter
    int getIndividualTripDuration() const { return m_individualTripDuration; }

    //setter
    void setIndividualTripDuration(int duration) { m_individualTripDuration = duration; }

    //<< overload to display details
    friend std::ostream& operator<<(std::ostream& os, const IndividualTrip& iTrip);

    //fare calculation
    float calculateFare() override;

    //function for checking trip standard
    bool isTripAsPerStandard();
};

#endif