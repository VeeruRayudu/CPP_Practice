#ifndef ACTUATOR_H
#define ACTUATOR_H
#include <iostream>
#include <string>

enum class ActuatorType {MOTOR, VALVE, DISPLAY};

class Actuator{
    private:
    ActuatorType m_type;

    public:
    //constructor
    Actuator(ActuatorType type);

    //enum to string 
    std::string toString(ActuatorType t) const;

    //display
    void showActuator() const;
};

#endif