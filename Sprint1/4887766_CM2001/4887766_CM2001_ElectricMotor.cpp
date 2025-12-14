#include "4887766_CM2001_ElectricMotor.h"

//constructor initialization
ElectricMotor::ElectricMotor(float maxPower_, int maxTorque_): m_maxPower(maxPower_), m_maxTorque(maxTorque_) {};

//getters
float ElectricMotor::getMaxPower() const { return m_maxPower; }
int ElectricMotor::getMaxTorque() const { return m_maxTorque; }

//setters
void ElectricMotor::setMaxPower(float maxPower_){ m_maxPower = maxPower_; }
void ElectricMotor::setMaxTorque(int maxTorque_) { m_maxTorque = maxTorque_; }

std::ostream& operator<<(std::ostream& os, ElectricMotor& eM){
    os<<"Max Power: "<<eM.m_maxPower<<"\n"
      <<"Max Torque: "<<eM.m_maxTorque<<"\n";

    return os;
}
