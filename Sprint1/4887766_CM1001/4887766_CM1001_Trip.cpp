#include "4887766_CM1001_Trip.h"

// default constructor
Trip::Trip(): m_tripID(""), m_tripDriver(""), m_tripDistance(0), m_tripRating(0), m_tripVehicleType(RIDE::REGULAR) {};
// std::string tripID_ = "", std::string tripDriver_ = "", int tripDistance_ = 0, int tripRating_ = 0, RIDE tripVehicleType_ = RIDE::REGULAR
// m_tripID(tripID_), m_tripDriver(tripDriver_), m_tripDistance(tripDistance_), m_tripRating(tripRating_), m_tripVehicleType(tripVehicleType_) 

// getters
std::string Trip::getTripID() const
{
    return m_tripID;
}
std::string Trip::getTripDriver() const
{
    return m_tripDriver;
}
int Trip::getTripDistance() const
{
    return m_tripDistance;
}
int Trip::getTripRating() const
{
    return m_tripRating;
}
RIDE Trip::getTripVehicleType() const
{
    return m_tripVehicleType;
}

// setters
void Trip::setTripID(std::string tripID_) { m_tripID = tripID_; }
void Trip::setTripDriver(std::string tripDriver_) { m_tripDriver = tripDriver_; }
void Trip::setTripDistance(int tripDistance_) { m_tripDistance = tripDistance_; }
void Trip::setTripRating(int tripRating_) { m_tripRating = tripRating_; }
void Trip::setTripVehicleType(RIDE tripVehicleType_) { m_tripVehicleType = tripVehicleType_; }

//fare calculation function
float Trip::calculateFare(){
    float fare = 0.0f;
    if(getTripVehicleType() == REGULAR){
        fare = getTripDistance() * 25;
    }else{
        fare = getTripDistance() * 50;
    }
    fare += fare*(18/100.0);
    return fare;
}