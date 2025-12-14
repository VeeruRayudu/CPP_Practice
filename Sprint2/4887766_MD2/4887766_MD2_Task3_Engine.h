#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>

enum class VehicleState
{
    PARKED,
    INTRANSIT,
    MAINTENANCE
};

class Engine
{
private:
    int m_horsePower;

public:
    // constructor
    Engine(int horsePower_) : m_horsePower(horsePower_) {}

    // getter
    int getHorsePower() const noexcept { return m_horsePower; }
};

#endif