#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <iostream>
#include <string>

enum class ActuatorType {
    MOTOR,
    VALVE,
    DISPLAY
};

// Converts ActuatorType enum to string
[[nodiscard]] std::string toString(const ActuatorType type);

class Actuator {
private:
    ActuatorType m_type;

public:
    explicit Actuator(ActuatorType type);

    void showActuator() const;
};

#endif // ACTUATOR_H