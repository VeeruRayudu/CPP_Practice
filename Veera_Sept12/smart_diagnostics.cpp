#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <memory> 
using namespace std;

class Sensor{
public:
    int id;
    float value;
    float threshold;
    string status;

    Sensor(int _id, float _value, float _threshold)
        : id(_id), value(_value), threshold(_threshold), status("OK") {}

    virtual ~Sensor() = default;
    virtual void simulateFault() = 0;

    bool isFaulty() const {
        return value > threshold;
    }

    virtual string typeName() const = 0;
};

class TemperatureSensor:public Sensor {
public:
    TemperatureSensor(int _id, float _value, float _threshold)
        : Sensor(_id, _value, _threshold) {}

    void simulateFault() override{
        value += 10.0f; 
        status = isFaulty() ? "FAULTY - High Temp" : "OK";
    }

    string typeName() const override {
        return "TemperatureSensor";
    }
};

class PressureSensor : public Sensor {
public:
    PressureSensor(int _id, float _value, float _threshold)
        : Sensor(_id, _value, _threshold) {}

    void simulateFault() override {
        value += 12.0f; 
        status = isFaulty() ? "FAULTY - High Pressure" : "OK";
    }
string typeName() const override {
        return "PressureSensor";
    }
};

class Actuator{
public:
    int id;
    string state;
    int responseTime; 

    Actuator(int _id, const std::string& _state, int _responseTime)
        : id(_id), state(_state), responseTime(_responseTime) {}

    void triggerAction() {
        if (state == "Idle") state = "Active";
        else state = "Idle";
        
        cout << "[Actuator " << id << "] triggered -> state: " << state << ", responseTime: " << responseTime << "ms\n";
    }
};

class FaultLogger {
    string filename;
    ofstream ofs;
public:
    FaultLogger(const string& fname = "faults.log") : filename(fname) {
        ofs.open(filename, ios::out | ios::app);
        if (!ofs.is_open()) {
            cerr << "Failed to open log file: " << filename << "\n";
        }
    }
    ~FaultLogger() {
        if (ofs.is_open()) ofs.close();
    }

    void log(Sensor& s) {
        if (!ofs.is_open()) return;
        ofs <<fixed <<setprecision(2)
            << "SensorID: " << s.id
            <<", Type: "<< s.typeName()
            <<", Value: " << s.value
            <<", Threshold: " << s.threshold
            <<", Status: "<< s.status << "\n";
    }
};

class ConfigManager{
public:
    void updateThreshold(Sensor& s, float newThreshold) {
        s.threshold = newThreshold;
        s.status = s.isFaulty() ? "FAULTY" : "OK";
    }
};

class FaultInjector{
public:
    vector<Sensor*> sensors;
    vector<Actuator*> actuators;

    ~FaultInjector() {
        sensors.clear();
        actuators.clear();
    }

    void injectSensorFault(Sensor* s) {
        if (!s) return;
        cout <<"Injecting sensor fault for ID " << s->id << "\n";
        s->simulateFault();
    }

    void injectActuatorDelay(Actuator& a){
        cout <<"Injecting actuator delay for ID " << a.id << "\n";
        a.responseTime += 200;
        a.state = "Delayed";
    }

    void injectAllFaults(){
        for (Sensor* s : sensors) {
            injectSensorFault(s);
        }
        for (Actuator* a : actuators) {
            if (a) injectActuatorDelay(*a);
        }
    }

    void reportStatus() {
        cout <<"FaultInjector Report \n";
        cout <<"Sensors:\n";
        for (Sensor* s : sensors) {
            cout << "ID: " << s->id << ", Type: " << s->typeName()
                      << "Value: " << s->value
                      <<"Thr: " << s->threshold
                      <<"Status: " << s->status << "\n";
        }
        cout << "Actuators:\n";
        for (Actuator* a : actuators) {
            cout << "  ID: " << a->id << ", State: " << a->state
                      << ", responseTime: " << a->responseTime << "ms\n";
        }
        cout <<"\n";
    }
};

void logFault(Sensor* s) {
    if (!s) return;
    cout << "[Global logFault] SensorID: " << s->id
              << ", Type: " << s->typeName()
              << ", Value: " << s->value
              << ", Threshold: " << s->threshold
              << ", Status: " << s->status << "\n";
}

void analyzeSystem(FaultInjector* fi) {
    if (!fi) return;
    cout << "\n--System Analysis--\n";
    int faultyCount = 0;
    for (Sensor* s : fi->sensors) {
        if (s->isFaulty()) faultyCount++;
    }
    cout << "Total sensors: " << fi->sensors.size()
              << ", Faulty sensors: " << faultyCount << "\n";
    int delayedActuators = 0;
    for (Actuator* a : fi->actuators) {
        if (a->state == "Delayed") delayedActuators++;
    }
    cout << "Total actuators: " << fi->actuators.size()
              << ", Delayed actuators: " << delayedActuators << "\n";
    
}

class SimulationEngine {
    ConfigManager& cfg;
    FaultLogger* logger; 
    FaultInjector injector;
    vector<Sensor*> ownedSensors;
    vector<Actuator*> ownedActuators;

public:
    SimulationEngine(ConfigManager& _cfg, FaultLogger* _logger)
        : cfg(_cfg), logger(_logger) {}

    void createTestObjects() {        TemperatureSensor* t1 = new TemperatureSensor(101, 95.0f, 90.0f);
        TemperatureSensor* t2=new TemperatureSensor(103, 85.0f, 90.0f); 
        PressureSensor* p1=new PressureSensor(102, 45.0f, 50.0f);
        Actuator* a1=new Actuator(201, "Idle", 120);
        Actuator* a2=new Actuator(202, "Idle", 150);

        ownedSensors.push_back(t1);
        ownedSensors.push_back(t2);
        ownedSensors.push_back(p1);
        ownedActuators.push_back(a1);
        ownedActuators.push_back(a2);

        injector.sensors = ownedSensors;
        injector.actuators = ownedActuators;
    }

    void run(int cycles = 3) {
        cout << "Starting simulation for " << cycles << " cycles\n";
        for (int i = 0; i < cycles; ++i) {
            cout << "\n--Cycle " << (i+1) << " \n";

            if (i == 1 && !ownedSensors.empty()) {
                cout << "Updating threshold for sensor ID "
                          << ownedSensors[1]->id << " via ConfigManager&\n";
                cfg.updateThreshold(*ownedSensors[1], 80.0f); 
            }
            injector.injectAllFaults();

            for (Actuator* a : injector.actuators) {
                if (a) a->triggerAction();
            }

            for (Sensor* s : injector.sensors) {
                if (s->isFaulty()) {
                    if (logger) {
                        logger->log(*s);   
                    }
                    logFault(s);
                }
            }
            injector.reportStatus();
            analyzeSystem(&injector);
        }
    }

    //final report 
    void generateReport() {
        std::cout << "Final System Report\n";
        injector.reportStatus();
        cout << "Owned sensors cleaned up count: " << ownedSensors.size() << "\n";
        cout << "Owned actuators cleaned up count: " << ownedActuators.size() << "\n";
        cout << "Log file: faults.log (appended entries)\n";
    }

    
    void cleanup(){
        for(Sensor* s : ownedSensors) {
            delete s;
        }
        ownedSensors.clear();

        for(Actuator* a : ownedActuators) {
            delete a;
        }
        ownedActuators.clear();
        injector.sensors.clear();
        injector.actuators.clear();
    }

    ~SimulationEngine() {
        cleanup();
    }
};

int main(){
    ConfigManager cfg;
    FaultLogger* logger=new FaultLogger("faults.log"); 

    SimulationEngine engine(cfg, logger);
    engine.createTestObjects();

    engine.run(3); 

    engine.generateReport();

    
    engine.cleanup();

    
    delete logger;

    cout << "Simulation finished,memory cleaned up.\n";
    return 0;
}
