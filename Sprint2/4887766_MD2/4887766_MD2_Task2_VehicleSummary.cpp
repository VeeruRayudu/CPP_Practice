#include "4887766_MD2_Task2_VehicleSummary.h"

// constructor
VehicleSummary::VehicleSummary(VIN vin_) : m_vin(vin_) {}

std::string VehicleSummary::info() const noexcept
{
    std::ostringstream oss;
    oss << "VIN: " << m_vin << std::endl;
    return oss.str();
}