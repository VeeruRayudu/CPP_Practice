#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <string>
#include <functional>
#include <ctime>

class Sensor{
    private:
    int m_id;
    std::string m_type;
    double m_value;
    double m_threshold;
    std::function<void(int, double)> onTrigger;

    public:
    //constructor
    Sensor(int id_, std::string type_, double value_, double threshold_);

    //updating value
    void update(double);

    //setting callback handler
    void setHandler(std::function<void(int, double)> handler);

    //getters
    double getThreshold() const { return m_threshold; }
};

//global functions
void logEvent(int id, double value);

class Logger{
    public:
    void log(int id, double value);
};

void dispatch(Sensor sensors[], int size);

#endif