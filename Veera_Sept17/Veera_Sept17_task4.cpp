#include <iostream>
#include <string>
#include <limits>


enum SensorType
{
    LIDAR,
    RADAR,
    CAMERA
};

const char* sensorTypeToString(SensorType t);

class SensorArray {
    private:
    int sensor_id;
    SensorType type;
    double* temperature_readings;
    int num_readings;

    static double global_max_temperature;

    public:

    SensorArray() : sensor_id(0), type(LIDAR), temperature_readings(nullptr), num_readings(0) {}


    // Constructor
    SensorArray(int id, SensorType t, const double* readings, int n)
        : sensor_id(id), type(t), num_readings(n)
    {
        
        temperature_readings = new double[num_readings];
        for (int i = 0; i < num_readings; i++)
        {
            temperature_readings[i] = readings[i];
            if (temperature_readings[i] > global_max_temperature)
            {
                global_max_temperature = temperature_readings[i];
            }
        }
    }

    ~SensorArray()
    {
        delete[] temperature_readings;
    }

    double getMaxTemperature() const
    {
        double maxTemp = std::numeric_limits<double>::lowest();
        for (int i = 0; i < num_readings; i++)
        {
            if (temperature_readings[i] > maxTemp)
            {
                maxTemp = temperature_readings[i];
            }
        }
        return maxTemp;
    }

    void printSensorInfo() const
    {
        std::cout << "Sensor ID: " << sensor_id
             << ", Type: " << sensorTypeToString(type)
             << ", Max Temperature: " << getMaxTemperature() << " °C" << std::endl;
    }

    static double getGlobalMaxTemperature()
    {
        return global_max_temperature;
    }

    SensorType getType() const { return type; }

    
};

double SensorArray::global_max_temperature = std::numeric_limits<double>::lowest();

const char* sensorTypeToString(SensorType t)
{
    switch (t)
    {
    case LIDAR:
        return "LIDAR";
    case RADAR:
        return "RADAR";
    case CAMERA:
        return "CAMERA";
    default:
        return "UNKNOWN";
    }
}

void printSensor(const SensorArray& s)
{
    s.printSensorInfo();
}

void printAllSensors(const SensorArray* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printSensor(arr[i]);
    }
}

int main()
{
    
    double lidarReadings[3] = {35.5, 36.1, 34.9};
    double radarReadings[3] = {39.0, 38.7, 39.3};
    double cameraReadings[3] = {30.2, 31.0, 30.5};

    
    int size = 3;
    SensorArray* sensors = new SensorArray[size] {
        SensorArray(801, LIDAR, lidarReadings, 3),
        SensorArray(802, RADAR, radarReadings, 3),
        SensorArray(803, CAMERA, cameraReadings, 3)
    };

    
    std::cout << "Sensor Information:\n";
    printAllSensors(sensors, size);

    
    std::cout << "\nGlobal Maximum Temperature: "
         << SensorArray::getGlobalMaxTemperature() << " °C" << std::endl;

    
    delete[] sensors;

    return 0;
}
