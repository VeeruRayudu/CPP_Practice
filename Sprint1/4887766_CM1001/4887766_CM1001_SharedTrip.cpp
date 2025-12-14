#include "4887766_CM1001_SharedTrip.h"

//default constructor
SharedTrip::SharedTrip() : Trip(), m_sharedTripPassengers(0) {};

//getter
int SharedTrip::getSharedTripPassengers() const { return m_sharedTripPassengers; }

//setter
void SharedTrip::setSharedTripPassengers(int passengers_){ m_sharedTripPassengers = passengers_; }

float SharedTrip::calculateFare(){
    float fare = 0.0f;
    if(getTripVehicleType() == REGULAR){
        fare = (getTripDistance() * 25) + (m_sharedTripPassengers * 5);
    }else{
        fare = (getTripDistance() * 50) + (m_sharedTripPassengers * 20);
    }
    fare += fare*(18/100.0);
    return fare;
}

bool SharedTrip::isTripAsPerStandard(){
    if(getTripVehicleType() == REGULAR){
        return ((getTripRating() >= 3) ? true : false);
    }else{
        return ((getTripRating() >= 4) ? true : false);
    }
}