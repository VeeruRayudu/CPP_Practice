#ifndef SENSOR_DISPATCHER
#define SENSOR_DISPATCHER
#include <iostream>
#include <variant>
#include <functional>
#include <memory>
#include <vector>

class Sensor{
    public:
    virtual ~Sensor() = default;
    virtual std::variant<int, double, std::string> readData() const = 0;
    virtual std::string getType() const = 0;
};

class SensorDispatcher{
    private:
    std::vector<std::function<void()>> m_tasks;
    std::vector<std::unique_ptr<Sensor>> m_sensors;

    public:
    //default constructor
    SensorDispatcher() = default;

    //defaulted move and copy operations
    SensorDispatcher(const SensorDispatcher&) = default;
    SensorDispatcher& operator=(const SensorDispatcher&) = default;
    SensorDispatcher(SensorDispatcher&) = default;
    SensorDispatcher& operator=(SensorDispatcher&&) = default;

    //adding sensor
    void addSensor(std::unique_ptr<Sensor> sensor);

    //scheduling tasks to sensors
    void scheduleTask(std::function<void()> task);

    void dispatch();
};

class TemperatureSensor: public Sensor{
    public:
    std::variant<int, double, std::string> readData() const override;

    std::string getType() const override;
};

class PressureSensor: public Sensor{
    public:
    std::variant<int, double, std::string> readData() const override;

    std::string getType() const override;
};

class SpeedSensor: public Sensor{
    public:
    std::variant<int, double, std::string> readData() const override;

    std::string getType() const override;
};

//free function
void processSensorData(const Sensor& sensor);

#endif