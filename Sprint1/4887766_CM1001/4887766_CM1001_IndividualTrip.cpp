#include "4887766_CM1001_IndividualTrip.h"

//default constructor
IndividualTrip::IndividualTrip(): Trip(), m_individualTripDuration(0) {};

//getter
int IndividualTrip::getIndividualTripDuration() const { return m_individualTripDuration; }

//setter
void IndividualTrip::setIndividualTripDuration(int duration_){ m_individualTripDuration = duration_; }

//fare calculation
float IndividualTrip::calculateFare() {
    return Trip::calculateFare();
}

float IndividualTrip::calculateFare(float surcharge){
    float fare = calculateFare();
    fare += surcharge * m_individualTripDuration;
    return fare;
}

bool IndividualTrip::isTripAsPerStandard(){
    if(getTripVehicleType() == REGULAR){
        if(getTripRating() >= 3 && m_individualTripDuration <= (3*getTripDistance())){
            return true;
        }else{
            return false;
        }
    }else{
        if(getTripRating() >= 4 && m_individualTripDuration <= (4*getTripDistance())){
            return true;
        }else{
            return false;
        }
    }
}