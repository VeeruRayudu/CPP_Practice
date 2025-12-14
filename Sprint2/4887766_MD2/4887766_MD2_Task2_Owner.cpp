#include "4887766_MD2_Task2_Owner.h"

// constructor initialization
Owner::Owner(std::string name_) : m_name(name_) {}

// add summary to vector
void Owner::addVehicle(const VehicleSummary *v)
{
    if (v != nullptr)
    {
        m_summaries.emplace_back(v);
    }
}

// listing vehicles
std::vector<std::string> Owner::listVehicles() const noexcept
{
    std::vector<std::string> str;
    for (auto &s : m_summaries)
    {
        str.emplace_back(s->info());
    }

    return str;
}

std::string ownerReport(const Owner &owner)
{
    std::ostringstream oss;

    std::vector<std::string> result = owner.listVehicles();

    oss << "Owner: " << owner.getName() << ", Vehicle count: " << result.size() << std::endl;

    return oss.str();
}