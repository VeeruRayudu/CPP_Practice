#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Sensor {
public:
    int id;
    float value;
    int priority;
    string status;

    Sensor(int _id, float _value, int _priority)
        : id(_id), value(_value),priority(_priority),status("OK"){}

    void updateValue(float v) {
        value = v;
        status = (v < 20.0 ? "FAULT" : "OK");
    }
};
class SensorDiagnostics {
public:
    string checkHealth(Sensor& s) {
        if (s.status == "OK")
            return "Sensor " + to_string(s.id) + " is healthy.";
        else
            return "Sensor " + to_string(s.id) + " is in fault!";
    }
};
void rebindCriticalSensor(Sensor*& ref, Sensor* list[], int size){
    if (size == 0) return;

    Sensor* highest = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i]->priority > highest->priority){
            highest = list[i];
        }
    }
    ref = highest;
}

void printSensorMap(Sensor* list[], int size){
    cout << "\n--- Sensor Map ---\n";
    for (int i = 0; i < size; i++) {
        cout << "Sensor ID: " << list[i]->id
             << ",Value: " << list[i]->value
             << ",Priority: " << list[i]->priority
             << ",Status: " << list[i]->status << endl;
    }
}

class Controller{
public:
    Sensor* sensorList[10];  
    Sensor& criticalSensor; 

    Controller(Sensor* list[], int size)
        : criticalSensor(*list[0]){
        for (int i = 0; i < size; i++)
            sensorList[i] = list[i];
        bindCriticalSensor();
    }

    void bindCriticalSensor() {
        Sensor* ref = &criticalSensor;
        rebindCriticalSensor(ref, sensorList, 10);
        const_cast<Sensor*&>(reinterpret_cast<Sensor*&>(criticalSensor)) = ref;
    }
    void updateCriticalSensor(float v) {
        criticalSensor.updateValue(v);
    }
    void printStatus() {
        SensorDiagnostics diag;
        cout << diag.checkHealth(criticalSensor) << endl;
    }
};

int main() {
    Sensor* sensors[10];
    for (int i = 0; i < 10; i++) {
        sensors[i] = new Sensor(i + 1, 50.0 + i * 5, (i % 7) + 1);
    }
    Controller ctrl(sensors, 10);
    printSensorMap(sensors, 10);
    ctrl.printStatus();

    cout << "\nUpdating critical sensor value\n";
    ctrl.updateCriticalSensor(10.0);
    ctrl.printStatus();

    cout << "\nRebinding critical sensor\n";
    ctrl.bindCriticalSensor();
    ctrl.printStatus();

    printSensorMap(sensors, 10);
    for (int i = 0; i < 10; i++) {
        delete sensors[i];
    }
    return 0;
}
