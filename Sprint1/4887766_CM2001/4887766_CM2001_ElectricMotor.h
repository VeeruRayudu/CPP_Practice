#ifndef ELECTRICMOTOR_H
#define ELECTRICMOTOR_H
#include <iostream>

class ElectricMotor{
    private:
    float m_maxPower;
    int m_maxTorque;

    public:
    //parameterized constructor
    ElectricMotor(float maxPower_ = 0.0, int maxTorque_ = 0);

    //getters
    float getMaxPower() const ;
    int getMaxTorque() const ;

    //setters
    void setMaxPower(float maxPower_);
    void setMaxTorque(int maxTorque_);

    //overload operator
    friend std::ostream& operator<<(std::ostream& os, ElectricMotor& eM);
};

#endif