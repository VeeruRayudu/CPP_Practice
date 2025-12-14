#include "4887766_MD1_Task3_Refactored_Vehicle.h"

// Parameterized constructor
Vehicle::Vehicle(const std::string& model, int year)
    : m_model(model), m_year(year) {}

// Default constructor delegating to parameterized one
Vehicle::Vehicle()
    : Vehicle("Generic", 2020) {}

// Display vehicle information
void Vehicle::show() const {
    std::cout << "Model: " << m_model << "\n"
              << "Year: " << m_year << std::endl;
}