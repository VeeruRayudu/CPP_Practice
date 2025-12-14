#include "4887766_CM2001_SharedTrip.h"

//default constructor
SharedTrip::SharedTrip(std::string tripID_ , int tripDistance_, int tripRating_ , RIDE tripVehicleType_, int sharedTripPassengers_) : Trip(tripID_, tripDistance_, tripRating_, tripVehicleType_), m_sharedTripPassengers(sharedTripPassengers_) {};

//getter
int SharedTrip::getSharedTripPassengers() const { return m_sharedTripPassengers; }

//setter
void SharedTrip::setSharedTripPassengers(int passengers_){ m_sharedTripPassengers = passengers_; }

//<< overload to display details
std::ostream& operator<<(std::ostream& os, const SharedTrip& sTrip){
    std::cout<<sTrip;
    os<<"Shared Trip Passengers: "<<sTrip.getSharedTripPassengers();

    return os;
}

float SharedTrip::calculateFare(){
    float fare = 0.0f;
    if(getTripVehicleType() == RIDE::REGULAR){
        fare = (getTripDistance() * 25.0f) + (m_sharedTripPassengers * 5);
    }else{
        fare = (getTripDistance() * 30.0f) + (m_sharedTripPassengers * 10);
    }
    return fare;
}

bool SharedTrip::isTripAsPerStandard(){
    if(getTripVehicleType() == REGULAR){
        return ((getTripRating() >= 3) ? true : false);
    }else{
        return ((getTripRating() >= 4) ? true : false);
    }
}