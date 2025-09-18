#include <iostream>
#include <iomanip>


class EgoVehicleData {
private:
    int numLanes;
    float* lanePositions;      
    float* sensorConfidence;   

public:
    // Constructor
    EgoVehicleData(int nl, const float* lp, const float* sc)
        : numLanes(nl)
    {
        lanePositions = new float[numLanes];
        for (int i = 0; i < numLanes; i++) {
            lanePositions[i] = lp[i];
        }

        sensorConfidence = new float[numLanes];
        for (int i = 0; i < numLanes; i++) {
            sensorConfidence[i] = sc[i];
        }
    }

    // Destructor
    ~EgoVehicleData() {
        delete[] lanePositions;
        delete[] sensorConfidence;
    }

    float getAverageLanePosition() const {
        float sum = 0;
        for (int i = 0; i < numLanes; i++) {
            sum += lanePositions[i];
        }
        return (numLanes > 0) ? (sum / numLanes) : 0.0f;
    }

    void updateSensorConfidence(float factor) {
        for (int i = 0; i < numLanes; i++) {
            sensorConfidence[i] *= factor;
        }
    }

    float getTotalConfidence() const {
        float sum = 0;
        for (int i = 0; i < numLanes; i++) {
            sum += sensorConfidence[i];
        }
        return sum;
    }

    friend void printEgoVehicleData(const EgoVehicleData& data);
    friend void findHighestConfidenceVehicle(EgoVehicleData* array, int size, const EgoVehicleData*& highest);
};


void printEgoVehicleData(const EgoVehicleData& data) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Lane Positions: ";
    for (int i = 0; i < data.numLanes; i++) {
        std::cout << data.lanePositions[i] << " ";
    }
    std::cout << "\nSensor Confidence: ";
    for (int i = 0; i < data.numLanes; i++) {
        std::cout << data.sensorConfidence[i] << " ";
    }
    std::cout << "\nAvg Lane Position = " << data.getAverageLanePosition()
         << ", Total Confidence = " << data.getTotalConfidence() << "\n\n";
}

void findHighestConfidenceVehicle(EgoVehicleData* array, int size, const EgoVehicleData*& highest) {
    if (size <= 0) {
        highest = nullptr;
        return;
    }
    highest = &array[0];
    float maxConf = array[0].getTotalConfidence();
    for (int i = 1; i < size; i++) {
        float conf = array[i].getTotalConfidence();
        if (conf > maxConf) {
            maxConf = conf;
            highest = &array[i];
        }
    }
}

void printHighestConfidenceVehicle(const EgoVehicleData* vehicle) {
    if (vehicle == nullptr) {
        std::cout << "No vehicle found.\n";
    } else {
        std::cout << "-----------Highest Confidence Vehicle---------\n";
        printEgoVehicleData(*vehicle);
    }
}


int main() {
    float lp1[] = {3.2f, 3.0f, 3.4f};
    float sc1[] = {0.95f, 0.97f, 0.93f};

    float lp2[] = {2.9f, 2.8f, 3.1f};
    float sc2[] = {0.92f, 0.90f, 0.88f};

    float lp3[] = {3.4f, 3.5f, 3.6f};
    float sc3[] = {0.99f, 0.98f, 0.97f};

    EgoVehicleData* vehicles = new EgoVehicleData[3] {
        EgoVehicleData(3, lp1, sc1),
        EgoVehicleData(3, lp2, sc2),
        EgoVehicleData(3, lp3, sc3)
    };

    vehicles[0].updateSensorConfidence(1.05f); 
    vehicles[1].updateSensorConfidence(0.95f); 
    vehicles[2].updateSensorConfidence(1.10f); 

    std::cout << "--------Ego Vehicle Data------\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "Vehicle " << (i + 1) << ":\n";
        printEgoVehicleData(vehicles[i]);
    }

    const EgoVehicleData* highest = nullptr;
    findHighestConfidenceVehicle(vehicles, 3, highest);
    printHighestConfidenceVehicle(highest);

    delete[] vehicles;

    return 0;
}
