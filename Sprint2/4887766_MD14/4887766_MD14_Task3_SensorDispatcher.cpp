#include "4887766_MD14_Task3_SensorDispatcher.h"

// adding sensor
void SensorDispatcher::addSensor(std::unique_ptr<Sensor> sensor)
{
    m_sensors.emplace_back(std::move(sensor));
}

// scheduling tasks to sensors
void SensorDispatcher::scheduleTask(std::function<void()> task)
{
    m_tasks.emplace_back(std::move(task));
}

void SensorDispatcher::dispatch()
{
    // Execute all scheduled tasks
    for (auto &t : m_tasks)
    {
        if (t)
        {
            t();
        }
    }

    for (const auto &s : m_sensors)
    {
        auto data = s->readData();
        auto printer = [&](const auto &value)
        {
            std::cout << "Dispatching " << s->getType() << ": " << value << '\n';
        };
        std::visit(printer, data);
    }
}

std::variant<int, double, std::string> TemperatureSensor::readData() const
{
    return 36.5;
}

std::string TemperatureSensor::getType() const
{
    return "TemperatureSensor";
}

std::variant<int, double, std::string> PressureSensor::readData() const
{
    return 101;
}

std::string PressureSensor::getType() const
{
    return "PressureSensor";
}

std::variant<int, double, std::string> SpeedSensor::readData() const
{
    return "55km/h";
}

std::string SpeedSensor::getType() const
{
    return "SpeedSensor";
}

// free function
void processSensorData(const Sensor &sensor)
{
    auto data = sensor.readData();
    auto print = [&](auto &&arg)
    {
        std::cout << "\nProcessing " << sensor.getType() << " : " << arg << std::endl;
    };
    std::visit(print, data);
}