#include "4887766_CM2001_IndividualTrip.h"

//constructor
IndividualTrip::IndividualTrip(std::string tripID_ , int tripDistance_, int tripRating_ , RIDE tripVehicleType_, int individualTripDuration_) :  Trip(tripID_, tripDistance_, tripRating_, tripVehicleType_),m_individualTripDuration(individualTripDuration_) {};

//<< overload to display details
std::ostream& operator<<(std::ostream& os, const IndividualTrip& iTrip){
    os<<static_cast<const Trip&>(iTrip);
    os<<"Individual Trip Duration: "<<iTrip.getIndividualTripDuration();

    return os;
}

//fare calculation
float IndividualTrip::calculateFare(){
    float fare = 0.0f;
    if(getTripVehicleType() == RIDE::REGULAR){
        fare = getTripDistance() * 25.0f;
    }else{
        fare = getTripDistance() * 30.0f;
    }
    return fare;
}

//function for checking trip standard
bool IndividualTrip::isTripAsPerStandard(){
    if(getTripVehicleType() == RIDE::REGULAR){
        if(getTripRating() >= 3 && getIndividualTripDuration() <= 3*getTripDistance()){
            return true;
        }else{
            return false;
        }
    }else{
        if(getTripRating() >= 4 && getIndividualTripDuration() <= 3*getTripDistance()){
            return true;
        }else{
            return false;
        }
    }
}