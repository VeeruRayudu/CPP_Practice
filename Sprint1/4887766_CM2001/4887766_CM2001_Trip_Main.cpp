#include "4887766_CM2001_IndividualTrip.h"
#include "4887766_CM2001_SharedTrip.h"

int main(){
    std::cout<<"\n------------------TC1-----------------\n";
    IndividualTrip itrip("101REG", 29, 3, RIDE::REGULAR, 58);
    std::cout<<(itrip.isTripAsPerStandard() ? "True" : "False")<<std::endl;

    std::cout<<"\n------------------TC2-----------------\n";
    SharedTrip sTrip("101REG", 29, 3, RIDE::REGULAR, 3);
    std::cout<<(sTrip.isTripAsPerStandard() ? "True" : "False")<<std::endl;

    std::cout<<"\n------------------TC3-----------------\n";
    std::cout<<"Individual Trip Fare: "<<itrip.calculateFare()<<std::endl;

    std::cout<<"\n------------------TC4-----------------\n";
    std::cout<<"Shared Trip Fare: "<<sTrip.calculateFare()<<std::endl;
}