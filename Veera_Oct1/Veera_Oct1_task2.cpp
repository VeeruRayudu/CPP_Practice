#include<iostream>
#include<iomanip>

class BatteryMonitor{
    private:
    std::string scooterID;
    int chargeCycles;
    float batteryCapacity;
    float originalCapacity;
    bool isActive;
    int *tripDistances;
    int tripCount;

    public:
    //constructor
    BatteryMonitor(const std::string& id, int cycles, float currentCapacity, 
                   float origCapacity, bool active, int numTrips)
        : scooterID(id), chargeCycles(cycles), batteryCapacity(currentCapacity),
          originalCapacity(origCapacity), isActive(active), tripCount(numTrips) {
        tripDistances = new int[tripCount];
        for (int i = 0; i < tripCount; ++i) {
            tripDistances[i] = 0;
        }
    }

    //Copy constructor
    BatteryMonitor(const BatteryMonitor& other)
        : scooterID(other.scooterID), chargeCycles(other.chargeCycles),
          batteryCapacity(other.batteryCapacity), originalCapacity(other.originalCapacity),
          isActive(other.isActive), tripCount(other.tripCount) {
        tripDistances = new int[tripCount];
        for (int i = 0; i < tripCount; ++i) {
            tripDistances[i] = other.tripDistances[i];
        }
    }

    BatteryMonitor& operator=(const BatteryMonitor& other) {
        if (this != &other) {
            delete[] tripDistances;
            scooterID = other.scooterID;
            chargeCycles = other.chargeCycles;
            batteryCapacity = other.batteryCapacity;
            originalCapacity = other.originalCapacity;
            isActive = other.isActive;
            tripCount = other.tripCount;
            
            tripDistances = new int[tripCount];
            for (int i = 0; i < tripCount; ++i) {
                tripDistances[i] = other.tripDistances[i];
            }
        }
        return *this;
    }

    ~BatteryMonitor() {
        delete[] tripDistances;
        std::cout << "Destructor called for " << scooterID << " - Memory deallocated\n";
    }

    float getHealthPercentage() const {
        return (batteryCapacity / originalCapacity) * 100.0f;
    }

    bool operator>(const BatteryMonitor& other) const {
        return this->getHealthPercentage() > other.getHealthPercentage();
    }

    bool operator<(const BatteryMonitor& other) const {
        return this->getHealthPercentage() < other.getHealthPercentage();
    }

    BatteryMonitor& operator+=(int additionalCycles) {
        chargeCycles += additionalCycles;
        
        float degradationRate = 0.001f;
        float capacityLoss = batteryCapacity * degradationRate * additionalCycles;
        batteryCapacity -= capacityLoss;
        
        if (batteryCapacity < 0) {
            batteryCapacity = 0;
        }
        
        return *this;
    }

    int& operator[](int index) {
        if (index < 0 || index >= tripCount) {
            std::cerr << "Error: Index " << index << " out of bounds for " << scooterID << std::endl;
            return tripDistances[0];
        }
        return tripDistances[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= tripCount) {
            std::cerr << "Error: Index " << index << " out of bounds for " << scooterID << std::endl;
            return tripDistances[0];
        }
        return tripDistances[index];
    }

    bool operator!() const {
        return !isActive;
    }

    friend std::ostream& operator<<(std::ostream& os, const BatteryMonitor& monitor) {
        os<< "Scooter ID: " << monitor.scooterID << std::endl;
        os<< "Charge Cycles: " << monitor.chargeCycles << std::endl;
        os<< "Battery Capacity: " << std::fixed << std::setprecision(2) 
        << monitor.batteryCapacity << " kWh" << std::endl;
        os<< "Original Capacity: " << monitor.originalCapacity << " kWh" << std::endl;
        os << "Battery Health: " << std::fixed << std::setprecision(1) 
           << monitor.getHealthPercentage() << "%" << std::endl;
        os << "Status: " << (monitor.isActive ? "Active" : "Inactive") << std::endl;
        os<< "Trip Count: " << monitor.tripCount << std::endl;
        os << "Trip Distances: ";
        for (int i=0; i<monitor.tripCount; ++i) {
            os << monitor.tripDistances[i];
            if (i < monitor.tripCount - 1) {
                os << ", ";
            }
        }
        os << std::endl;
        return os;
    }

    std::string getID() const { return scooterID; }
    int getTripCount() const { return tripCount; }
    const int* getTripDistances() const { return tripDistances; }
};

int main() {
    std::cout << "--Battery Health Monitor System--" << std::endl;
    std::cout << "Creating scooter objects..." << std::endl;
    
    BatteryMonitor s1("SCT101", 300, 4.0, 5.0, true, 3);  
    BatteryMonitor s2("SCT202", 150, 3.5, 5.0, true, 2);  
    
    s1[0] = 12;
    s1[1] = 18;
    s1[2] = 25;
    
    s2[0] = 10;
    s2[1] = 15;
    
    std::cout << "Scooter 1:\n" << s1 << std::endl;
    std::cout << "Scooter 2:\n" << s2 << std::endl;
    
    if (s1 > s2) {
        std::cout << s1.getID() << " has better battery health than " << s2.getID() << std::endl;
    } else if (s1 < s2) {
        std::cout << s2.getID() << " has better battery health than " << s1.getID() << std::endl;
    } else {
        std::cout << "Both scooters have equal battery health" << std::endl;
    }
    
    std::cout << "Before adding cycles - " << s1.getID() << " health: "<< std::fixed << std::setprecision(1) << s1.getHealthPercentage() << "%" << std::endl;
    
    s1 += 50; 
    
    std::cout << "After adding 50 cycles - " << s1.getID() << " health: "<< s1.getHealthPercentage() << "%" << std::endl;
    
    if (!s1) {
        std::cout << s1.getID() << " is inactive" << std::endl;
    } else {
        std::cout << s1.getID() << " is active" << std::endl;
    }
    
    BatteryMonitor s3("SCT303", 100, 4.5, 5.0, false, 1);
    if (!s3) {
        std::cout << s3.getID() << " is inactive" << std::endl;
    } else {
        std::cout << s3.getID() << " is active" << std::endl;
    }
    
    std::cout << "Before copy:" << std::endl;
    std::cout << "s1 address: " << &s1 << ", s2 address: " << &s2 << std::endl;
    
    BatteryMonitor s4 = s1;
    std::cout << "After copy constructor (s4 = s1):" << std::endl;
    std::cout << "s4:\n" << s4 << std::endl;
    
    s2 = s1; 
    std::cout << "After assignment (s2 = s1):" << std::endl;
    std::cout << "s2:\n" << s2 << std::endl;
    
    std::cout << "Verifying deep copy" << std::endl;
    s1[0] = 99; 
    std::cout << "After modifying s1[0] to 99:" << std::endl;
    std::cout << "s1[0] = " << s1[0] << std::endl;
    std::cout << "s2[0] = " << s2[0] << " (should still be original value)" << std::endl;
    std::cout << "s4[0] = " << s4[0] << " (should still be original value)" << std::endl;
    
    std::cout << "\nProgram ending - Destructors will be called" << std::endl;
    
    return 0;
}