#include <iostream>
#include <string>
#include "4887766_CM1001_IndividualTrip.h"
#include "4887766_CM1001_SharedTrip.h"

int main(){
    IndividualTrip it1;
    SharedTrip st1;

    //TC1
    std::cout<<"\n--------------------TC1-----------------------\n";
    it1.setTripID("101REG");
    it1.setTripDriver("Ram");
    it1.setTripDistance(29);
    it1.setTripRating(3);
    it1.setTripVehicleType(REGULAR);
    it1.setIndividualTripDuration(58);

    std::cout<<((it1.isTripAsPerStandard()) ? "True" : "Fale");

    //TC2
    std::cout<<"\n--------------------TC2-----------------------\n";
    st1.setTripID("101REG");
    st1.setTripDriver("Raj");
    st1.setTripDistance(29);
    st1.setTripRating(3);
    st1.setTripVehicleType(REGULAR);
    st1.setSharedTripPassengers(3);

    std::cout<<((st1.isTripAsPerStandard()) ? "True" : "Fale");

    //TC3
    std::cout<<"\n--------------------TC3-----------------------\n";
    it1.setTripID("101REG");
    it1.setTripDriver("Jay");
    it1.setTripDistance(29);
    it1.setTripRating(3);
    it1.setTripVehicleType(REGULAR);
    it1.setIndividualTripDuration(58);

    std::cout<<it1.calculateFare();

    //TC4
    std::cout<<"\n--------------------TC4-----------------------\n";
    it1.setTripID("101REG");
    it1.setTripDriver("Rajesh");
    it1.setTripDistance(29);
    it1.setTripRating(3);
    it1.setTripVehicleType(REGULAR);
    it1.setIndividualTripDuration(58);

    std::cout<<it1.calculateFare(12.0);

    //TC5
    std::cout<<"\n--------------------TC5-----------------------\n";
    st1.setTripID("101REG");
    st1.setTripDriver("Jayesh");
    st1.setTripDistance(29);
    st1.setTripRating(3);
    st1.setTripVehicleType(REGULAR);
    st1.setSharedTripPassengers(3);

    std::cout<<st1.calculateFare();

    return 0;

}