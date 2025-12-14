#ifndef TRIP_H
#define TRIP_H
#include <iostream>
#include <string>

enum RIDE { REGULAR, PREMIUM};

class Trip{
    protected:
    std::string m_tripID;
    std::string m_tripDriver;
    int m_tripDistance;
    int m_tripRating;
    RIDE m_tripVehicleType;

    public:
    Trip(); //default constructor
    // std::string tripID_, std::string tripDriver_, int tripDistance_, int tripRating_, RIDE tripVehicleType_

    //getters
    std::string getTripID() const;
    std::string getTripDriver() const;
    int getTripDistance() const;
    int getTripRating() const;
    RIDE getTripVehicleType() const;

    //setters
    void setTripID(std::string tripID_);
    void setTripDriver(std::string tripDriver_);
    void setTripDistance(int tripDistance_);
    void setTripRating(int tripRating_);
    void setTripVehicleType(RIDE tripVehicleType_);

    //utility
    virtual float calculateFare();
};

#endif