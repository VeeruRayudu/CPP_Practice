#include "4887766_CM1001_Vehicle.h"

Vehicle::Vehicle() : m_numberOfTestRuns(2), m_type(VehicleType::PASSENGER)
{
    m_vehicleID = new char[10];
    std::strcpy(m_vehicleID, "UNKNOWN");
    m_testScores = new int[m_numberOfTestRuns]{0, 0};
}; // default

Vehicle::Vehicle(unsigned int numberOfTestRuns_) : m_type(VehicleType::COMMERCIAL)
{
    if (numberOfTestRuns_ > 5)
    {
        numberOfTestRuns_ = 5;
    }
    m_numberOfTestRuns = numberOfTestRuns_;
    m_vehicleID = new char[10];
    std::strcpy(m_vehicleID, "UNKNOWN");
    m_testScores = new int[m_numberOfTestRuns];
    for (int i = 0; i < m_numberOfTestRuns; i++)
    {
        m_testScores[i] = 0;
    }
}; // parameterized

Vehicle::Vehicle(const Vehicle &other)
{
    this->m_numberOfTestRuns = other.m_numberOfTestRuns;
    this->m_type = other.m_type;
    this->m_vehicleID = new char[std::strlen(other.m_vehicleID) + 1];
    std::strcpy(this->m_vehicleID, other.m_vehicleID);
    this->m_testScores = new int[m_numberOfTestRuns];
    for (int i = 0; i < m_numberOfTestRuns; i++)
    {
        this->m_testScores[i] = other.m_testScores[i];
    }
}

Vehicle::~Vehicle()
{
    delete[] m_testScores;
    delete[] m_vehicleID;
}

Vehicle &Vehicle::operator=(const Vehicle &other)
{
    if (this != &other)
    {
        delete[] m_testScores;
        delete[] m_vehicleID;
        this->m_numberOfTestRuns = other.m_numberOfTestRuns;
        this->m_type = other.m_type;
        this->m_vehicleID = new char[std::strlen(other.m_vehicleID) + 1];
        std::strcpy(this->m_vehicleID, other.m_vehicleID);
        this->m_testScores = new int[m_numberOfTestRuns];
        for (int i = 0; i < m_numberOfTestRuns; i++)
        {
            this->m_testScores[i] = other.m_testScores[i];
        }
    }
    return *this;
}

bool Vehicle::operator==(const Vehicle &other)
{
    return (this->averageScore() == other.averageScore());
}

int Vehicle::operator[](int index)
{
    if (index < 0 || index >= m_numberOfTestRuns)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return m_testScores[index];
}

double Vehicle::averageScore() const
{
    int sum = 0;
    for (int i = 0; i < m_numberOfTestRuns; i++)
    {
        sum += m_testScores[i];
    }
    return (m_numberOfTestRuns > 0) ? sum / m_numberOfTestRuns : 0;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &v)
{
    os << "Vehicle ID: " << v.m_vehicleID
       << ", Type: " << ((v.m_type == VehicleType::COMMERCIAL) ? "COMMERCIAL" : "PASSENGER") << ", Test Runs: " << v.m_numberOfTestRuns << ", Scores: ";
    for (int i = 0; i < v.m_numberOfTestRuns; i++)
    {
        os << v.m_testScores[i] << " ";
    }
    os << "Average score: " << v.averageScore();

    return os;
}

std::istream &operator>>(std::istream &is, Vehicle &v)
{
    char tempID[50];
    int type;

    std::cout << "Enter Vehicle ID: ";
    is >> tempID;
    delete[] v.m_vehicleID;
    v.m_vehicleID = new char[std::strlen(tempID) + 1];
    std::strcpy(v.m_vehicleID, tempID);

    std::cout << "Enter number of test runs (max 5): ";
    is >> v.m_numberOfTestRuns;

    delete[] v.m_testScores;
    v.m_testScores = new int[v.m_numberOfTestRuns];
    std::cout << "Enter " << v.m_numberOfTestRuns << " test scores: ";
    for (int i = 0; i < v.m_numberOfTestRuns; i++)
    {
        is >> v.m_testScores[i];
    }

    std::cout << "Enter Vehicle type (0 for COMMERCIAL, 1 for PASSENGER)";
    is >> type;
    v.m_type = (type == 0) ? VehicleType::COMMERCIAL : VehicleType::PASSENGER;

    return is;
}

void findMinAvgScore(Vehicle vArr[], int size)
{
    double minAvg = vArr[0].averageScore();
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (vArr[i].averageScore() < minAvg)
        {
            minAvg = vArr[i].averageScore();
            minIndex = i;
        }
    }
    std::cout << "\nVehicle with minimum average score:\n"
              << vArr[minIndex] << "\n";
}

VehicleType Vehicle::getVehicleType() const{
    return m_type;
}

void showVehicles(Vehicle vArr[], int size, VehicleType type)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (vArr[i].getVehicleType() == type)
        {
            std::cout << "\nVehicle found\n";
            found = true;
        }
    }
    if (!found)
    {
        throw std::invalid_argument("Not found!");
    }
}
