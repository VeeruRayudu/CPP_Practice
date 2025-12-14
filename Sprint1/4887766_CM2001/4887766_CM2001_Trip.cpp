#include "4887766_CM2001_Trip.h"

//constructor initialization
Trip::Trip(std::string tripID_ , int tripDistance_, int tripRating_, RIDE tripVehicleType_) : m_tripID(tripID_), m_tripDistance(tripDistance_), m_tripRating(tripRating_), m_tripVehicleType(tripVehicleType_) {};

Trip::~Trip() {}

std::string Trip::typeToString(RIDE r){
    switch (r)
    {
    case RIDE::COMFORT: return "COMFORT";
    case RIDE::REGULAR: return "REGULAR";
    default: return "UNKNOWN";
    }
}

//overload operator to display details
std::ostream& operator<<(std::ostream& os, const Trip& trip){
    os <<"Trip ID: "<<trip.getTripID()<<"\n"
       <<"Trip Distance: "<<trip.getTripDistance()<<"\n"
       <<"Trip Rating: "<<trip.getTripRating()<<"\n"
       <<"Trip Vehicle Type: "<<(trip.getTripVehicleType() == RIDE::REGULAR ? "REGULAR" : "COMFORT")<<"\n";

       return os;
}

