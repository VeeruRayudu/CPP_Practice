#include "4887766_MD5_Task1_Sensor.h"

int main(){
    Sensor sensors[3] = {
        {101, "Temp", 75.0, 70.0},
        {102, "Pressure", 95.0, 90.0},
        {103, "Humidity", 45.0, 50.0}
    };

    //lambda handler
    double threshold = sensors[0].getThreshold();
    sensors[0].setHandler([=](int id, double value){
        std::cout << "[Lambda by value] Sensor " << id
                  << " exceeded threshold " << threshold << " with value: " << value << "\n";
    });

    //bound member function handler
    Logger logger;
    sensors[1].setHandler(std::bind(&Logger::log, &logger, std::placeholders::_1, std::placeholders::_2));

    //wrapped free function handler
    sensors[2].setHandler(std::ref(logEvent));

    //simulating sensor updates
    dispatch(sensors, 3);

    //updating lambda handler to capture by ref
    std::cout << "\n--- Changing lambda to capture by reference ---\n";
    sensors[0].setHandler([&threshold](int id, int value){
        std::cout << "[Lambda by reference] Sensor " << id
                  << " exceeded threshold " << threshold << " with value: " << value << "\n";
    });
    threshold = 60.0;
    dispatch(sensors, 3);

    //assigning mutable lambda
    std::cout << "\n--- Mutable lambda counting triggers ---\n";
    sensors[0].setHandler([count = 0](int id, double value) mutable{
        ++count;
        std::cout<<"[Mutable Lambda] Sensor " << id
                  << " triggered " << count << " times, value: " << value << "\n";
    });
    dispatch(sensors, 3);
    dispatch(sensors, 3);
}