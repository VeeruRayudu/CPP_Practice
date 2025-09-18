#include <iostream>
#include <iomanip>
#include <string>


enum SatelliteStatus {
    OPERATIONAL,
    MAINTENANCE,
    DECOMMISSIONED
};

class SatelliteData {
private:
    int satelliteID;
    int numAntennas;
    float* signalStrength;
    float orbitalAltitude;
    SatelliteStatus status;

    static int activeSatellites; 
public:
    // Constructor
    SatelliteData(int id, int n_ant, const float* signals, float altitude, SatelliteStatus st)
        : satelliteID(id), numAntennas(n_ant), orbitalAltitude(altitude), status(st) 
    {
        signalStrength = new float[numAntennas];
        for (int i = 0; i < numAntennas; i++) {
            signalStrength[i] = signals[i];
        }
        activeSatellites++;
    }

    // Copy Constructor
    SatelliteData(const SatelliteData& other)
        : satelliteID(other.satelliteID),
          numAntennas(other.numAntennas),
          orbitalAltitude(other.orbitalAltitude),
          status(other.status)
    {
        signalStrength = new float[numAntennas];
        for (int i = 0; i < numAntennas; i++) {
            signalStrength[i] = other.signalStrength[i];
        }
        activeSatellites++;
    }

    // Destructor
    ~SatelliteData() {
        delete[] signalStrength;
        activeSatellites--;
    }

    float getAverageSignalStrength() const {
        float sum = 0;
        for (int i = 0; i < numAntennas; i++) {
            sum += signalStrength[i];
        }
        return (numAntennas > 0) ? (sum / numAntennas) : 0.0f;
    }

    void boostSignal(float factor) {
        for (int i = 0; i < numAntennas; i++) {
            signalStrength[i] *= factor;
        }
    }

    void boostSignal(float factor, float threshold) {
        for (int i = 0; i < numAntennas; i++) {
            if (signalStrength[i] < threshold) {
                signalStrength[i] *= factor;
            }
        }
    }

    static int getActiveSatelliteCount() {
        return activeSatellites;
    }

    void setStatus(SatelliteStatus new_status) {
        status = new_status;
    }

    std::string getStatusString() const {
        switch (status) {
            case OPERATIONAL: return "OPERATIONAL";
            case MAINTENANCE: return "MAINTENANCE";
            case DECOMMISSIONED: return "DECOMMISSIONED";
            default: return "UNKNOWN";
        }
    }

    friend void printSatelliteData(const SatelliteData& sd);
    friend bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2);
    friend void cloneSatellite(const SatelliteData& source, SatelliteData*& target);
    friend void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold);
};

int SatelliteData::activeSatellites = 0;


void printSatelliteData(const SatelliteData& sd) {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Satellite ID: " << sd.satelliteID << "\n";
    std::cout << "Altitude: " << sd.orbitalAltitude << " km\n";
    std::cout << "Signal Strengths: ";
    for (int i = 0; i < sd.numAntennas; i++) {
        std::cout << sd.signalStrength[i] << " ";
    }
    std::cout << "\nStatus: " << sd.getStatusString() << "\n\n";
}

bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2) {
    return s1.orbitalAltitude > s2.orbitalAltitude;
}

void cloneSatellite(const SatelliteData& source, SatelliteData*& target) {
    target = new SatelliteData(source); 
}

void printActiveSatelliteCount() {
    std::cout << "Active Satellites: " << SatelliteData::getActiveSatelliteCount() << "\n";
}

void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold) {
    if (sd.getAverageSignalStrength() < confidence_threshold) {
        sd.setStatus(MAINTENANCE);
    }
}


int main() {
    float signals1[] = {78.5f, 80.2f, 79.0f};
    SatelliteData* sat1 = new SatelliteData(101, 3, signals1, 550.0f, OPERATIONAL);

    float signals2[] = {75.0f, 76.5f};
    SatelliteData* sat2 = new SatelliteData(102, 2, signals2, 600.0f, MAINTENANCE);

    sat1->boostSignal(1.05f);           
    sat2->boostSignal(1.10f, 76.0f);    

    std::cout << (compareAltitude(*sat1, *sat2)?"Sat1 higher altitude\n\n" : "Sat2 higher altitude\n\n");

    SatelliteData* sat3 = nullptr;
    cloneSatellite(*sat1, sat3);

    std::cout << "----Satellite 1-----\n"; printSatelliteData(*sat1);
    std::cout << "----Satellite 2----\n"; printSatelliteData(*sat2);
    std::cout << "----Satellite 3 (Clone of Sat1)----\n"; printSatelliteData(*sat3);

    updateStatusIfWeak(*sat2, 78.0f);

    std::cout << "-----After Status Update-------\n";
    printSatelliteData(*sat2);

    printActiveSatelliteCount();

    delete sat1;
    delete sat2;
    delete sat3;

    printActiveSatelliteCount();

    return 0;
}
