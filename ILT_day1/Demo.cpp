#include <iostream>

class Engine{
    public:
    void ignite(){
        std::cout<<"Engine ignited"<<std::endl;
    }
};

class Break{
    public:
    void applyBreak(){
        std::cout<<"Breaks applied"<<std::endl;
    }
};

// class Car{
//     private:
//     Engine engine;
//     Break breaks;
//     public:
//     void start(){
//         engine.ignite();
//     }
//     void stop(){
//         breaks.applyBreak();
//     }
// };

class Sensor{
    public:
    std::string sensorID;
    Sensor(std::string id): sensorID(id) {};
    double readSensor(){
        return 12.3;
    }
};

class DiagnosticTool{
    private:
    Sensor* sensor;
    public:
    DiagnosticTool(Sensor* s): sensor(s) {};
    void runDiagnostics(){
        std::cout<<"Sensor ID: "<<sensor->sensorID<<" Reading: "<<sensor->readSensor()<<std::endl;
    }
};

class Vehicle{
    protected:
    std::string make;
    int yearOfManufacturing;
    public:
    Vehicle(std::string make_, int yearOfManufacturing_): make(make_), yearOfManufacturing(yearOfManufacturing_) {};
    virtual void start(){
        std::cout<<make<<" of "<<yearOfManufacturing<<" Vehicle Started! \n";
    }
    virtual void stop(){
        std::cout<<make<<" of "<<yearOfManufacturing<<" Vehicle Stopped! \n";
    }
    virtual void runDiagnostics() = 0;
};

class Car: public Vehicle{
    private:
    std::string model;
    int numberOfSeats;
    public:
    Car(std::string make_, int yearOfManufacturing_, std::string model_, int numberOfSeats_): Vehicle(make_, yearOfManufacturing_), model(model_), numberOfSeats(numberOfSeats_) {};
    void honk(){
        std::cout<<"Car honked \n";
    }
    void showDetails(){
        std::cout<<make<<" "<<yearOfManufacturing<<" "<<model<<" "<<numberOfSeats<<std::endl;
    }
    void start() override {
        std::cout<<"Car started from from car class \n";
    }
    void stop() override {
        std::cout<<"Car stopped from car class"<<std::endl;
    }
    void runDiagnostics() override{
        std::cout<<"Executing car diagnostics"<<std::endl;
    }

};

int main(){
    Vehicle v1("Tata", 2025);
    Car car1("Tata", 2025, "Nexon", 5);
    // v1.start();
    // v1.stop(); 
    car1.start();
    car1.honk();
    car1.showDetails();
    car1.stop();
    std::cout<<"--------------\n";
    Vehicle* vPtr = new Car("Tata", 2025, "Nexon", 5);
    vPtr->start();
    vPtr->stop();
    std::cout<<"--------------\n";
    Car car("Tata", 2025, "Nexon", 5);
    Vehicle& vRef = car;
    vRef.start();
    vRef.stop();
    vRef.runDiagnostics();

    Sensor* sensor = new Sensor("BreakSensor");
    DiagnosticTool tool(sensor);
    tool.runDiagnostics();

    return 0;
}