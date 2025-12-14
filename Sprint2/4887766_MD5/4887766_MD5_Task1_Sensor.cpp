#include "4887766_MD5_Task1_Sensor.h"

// constructor
Sensor::Sensor(int id_, std::string type_, double value_, double threshold_) : m_id(id_), m_type(type_), m_value(value_), m_threshold(threshold_) {};

// updating value
void Sensor::update(double newValue){
    m_value = newValue;
    if(newValue > m_threshold){
        onTrigger(m_id, m_value);
    }
}

// setting callback handler
void Sensor::setHandler(std::function<void(int, double)> handler){
    onTrigger = std::move(handler);
}

// global functions
void logEvent(int id, double value){
    std::cout<<"\n[Free function]Sensor ID: "<<id<<", triggered at value: "<<value<<std::endl;
}

void Logger::log(int id, double value){
    std::cout<<"\nLogger::Sensor ID: "<<id<<", triggered at value: "<<value<<std::endl;
}

void dispatch(Sensor sensors[], int size){
    std::cout << "\n--- Dispatching Sensor Updates ---\n";
    std::srand((unsigned)std::time(nullptr));
    for(int i=0; i<size; i++){
        double randomValue = sensors[i].getThreshold() + (std::rand()% 20-5);
        sensors[i].update(randomValue);
    }
}