#include "4887766_MD1_Task3_Vehicle.h"

//constructor initialization
Vehicle::Vehicle(std::string model_, int year_): m_model(model_), m_year(year_) {};

Vehicle::Vehicle(): Vehicle("Generic", 2020) {};

void Vehicle::show() const{
    std::cout<<"Model: "<<m_model<<"\n"<<"Year: "<<m_year<<"\n";
}