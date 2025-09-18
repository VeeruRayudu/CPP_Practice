#include <iostream>
#include <iomanip>

class VehicleStatus {
private:
    int numWheels;
    float* wheelSpeed;     
    int numTemps;
    float* engineTemp;     

public:
    VehicleStatus(int nw, const float* ws, int nt, const float* et)
        : numWheels(nw), numTemps(nt)
    {
        wheelSpeed = new float[numWheels];
        for (int i = 0; i < numWheels; i++) {
            wheelSpeed[i] = ws[i];
        }

        engineTemp = new float[numTemps];
        for (int i = 0; i < numTemps; i++) {
            engineTemp[i] = et[i];
        }
    }

    // Destructor
    ~VehicleStatus() {
        delete[] wheelSpeed;
        delete[] engineTemp;
    }

    float averageWheelSpeed() const {
        float sum = 0;
        for (int i = 0; i < numWheels; i++) {
            sum += wheelSpeed[i];
        }
        return (numWheels > 0) ? (sum / numWheels) : 0.0f;
    }

    float maxEngineTemp() const {
        float maxVal = engineTemp[0];
        for (int i = 1; i < numTemps; i++) {
            if (engineTemp[i] > maxVal)
                maxVal = engineTemp[i];
        }
        return maxVal;
    }

    bool isWheelSpeedHigher(const VehicleStatus& other) const {
        float myMax = wheelSpeed[0];
        for (int i = 1; i < numWheels; i++) {
            if (wheelSpeed[i] > myMax)
                myMax = wheelSpeed[i];
        }

        float otherMax = other.wheelSpeed[0];
        for (int i = 1; i < other.numWheels; i++) {
            if (other.wheelSpeed[i] > otherMax)
                otherMax = other.wheelSpeed[i];
        }

        return (this->numWheels > 0 && myMax > otherMax);
    }

    friend void printVehicleStatus(const VehicleStatus& vs);
    friend bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2);
};

void printVehicleStatus(const VehicleStatus& vs) {
    std::cout << "Wheel Speeds: ";
    for (int i = 0; i < vs.numWheels; i++) {
       std::cout << std::fixed << std::setprecision(1) << vs.wheelSpeed[i] << " ";
    }
    std::cout << "\nEngine Temps: ";
    for (int i = 0; i < vs.numTemps; i++) {
        std::cout << std::fixed << std::setprecision(1) << vs.engineTemp[i] << " ";
    }
    std::cout << "\nAvg Wheel Speed = " << vs.averageWheelSpeed();
    std::cout << ", Max Engine Temp = " << vs.maxEngineTemp() << "\n\n";
}

bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2) {
    return vs1.isWheelSpeedHigher(vs2);
}

int main() {
    float ws1[] = {55.5f, 56.6f, 57.2f, 55.9f};
    float et1[] = {90.5f, 88.9f};
    VehicleStatus v1(4, ws1, 2, et1);

    float ws2[] = {50.0f, 51.2f, 49.8f, 50.4f};
    float et2[] = {92.0f, 89.5f};
    VehicleStatus v2(4, ws2, 2, et2);

    std::cout << "------Vehicle 1 Status-------\n";
    printVehicleStatus(v1);

    std::cout << "------Vehicle 2 Status----------------\n";
    printVehicleStatus(v2);

    std::cout << "Comparison (Member Function): ";
    std::cout << (v1.isWheelSpeedHigher(v2) ? "Vehicle 1 faster\n" : "Vehicle 2 faster or equal\n");

    std::cout << "Comparison (Global Function): ";
    std::cout << "Comparison (Global Function): ";
    std::cout << (compareWheelSpeedGlobal(v1, v2) ? "Vehicle 1 faster\n" : "Vehicle 2 faster or equal\n");

    return 0;
}
