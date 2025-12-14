#include "4887766_MD14_Task3_SensorDispatcher.h"

int main(){
    SensorDispatcher dispatcher;

    auto temp = std::make_unique<TemperatureSensor>();
    Sensor* tempRaw = temp.get();
    auto press = std::make_unique<PressureSensor>();
    Sensor* pressRaw = press.get();
    auto speed = std::make_unique<SpeedSensor>();
    Sensor* speedRaw = speed.get();

    dispatcher.addSensor(std::move(temp));
    dispatcher.addSensor(std::move(press));
    dispatcher.addSensor(std::move(speed));

    // dispatcher.scheduleTask([&dispatcher](){dispatcher.dispatch();});

    std::function<void()> emptyTask;
    dispatcher.scheduleTask(emptyTask);

    dispatcher.dispatch();

    processSensorData(*tempRaw);
    processSensorData(*pressRaw);
    processSensorData(*speedRaw);

    SensorDispatcher emptyDispatcher;
    emptyDispatcher.dispatch();

    dispatcher.addSensor(std::make_unique<TemperatureSensor>());
    dispatcher.dispatch();

    emptyDispatcher = std::move(dispatcher);
    emptyDispatcher.dispatch();

    return 0;
}