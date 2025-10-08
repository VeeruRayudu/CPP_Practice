#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

//Enum Class SeverityLevel
enum class SeverityLevel {
    Low,
    Medium,
    High,
    Critical
};
std::string severityToString(SeverityLevel level) {
    switch(level) {
        case SeverityLevel::Low: return "Low";
        case SeverityLevel::Medium: return "Medium";
        case SeverityLevel::High: return "High";
        case SeverityLevel::Critical: return "Critical";
        default: return "Unknown";
    }
}

//Class SensorReading
class SensorReading {
private:
    std::string sensorName;
    double value;
    SeverityLevel severity;

public:
    //Constructor
    SensorReading(const std::string& name, double val, SeverityLevel sev)
        : sensorName(name), value(val), severity(sev) {}

    void displayReading() const {
        std::string severityStr;
        switch(severity) {
            case SeverityLevel::Low: severityStr = "Low"; break;
            case SeverityLevel::Medium: severityStr = "Medium"; break;
            case SeverityLevel::High: severityStr = "High"; break;
            case SeverityLevel::Critical: severityStr = "Critical"; break;
        }
        std::cout<<sensorName<<"\t"<<value<<"\t"<<severityStr<<std::endl;
    }

    SeverityLevel getSeverity() const {
        return severity;
    }
    std::string getSensorName() const {
        return sensorName;
    }
};

//class DiagnosticReport
class DiagnosticReport {
private:
    std::vector<SensorReading> readings;

public:
    void addReading(const SensorReading& reading) {
        readings.push_back(reading);
    }

    void displayAllReadings() const {
        for(const auto& reading : readings) {
            reading.displayReading();
        }
    }

    int countSeverityOrHigher(SeverityLevel minSeverity) const {
        int count = 0;
        for(const auto& reading : readings) {
            if(reading.getSeverity() >= minSeverity) {
                count++;
            }
        }
        return count;
    }

    //Severity-Based Filtering
    std::vector<SensorReading> filterBySeverity(SeverityLevel level) const {
        std::vector<SensorReading> filteredReadings;
        for(const auto& reading : readings) {
            if(reading.getSeverity() == level) {
                filteredReadings.push_back(reading);
            }
        }
        return filteredReadings;
    }

    //Sorting by Severity
    void sortBySeverityDescending() {
        std::sort(readings.begin(), readings.end(), 
            [](const SensorReading& a, const SensorReading& b) {
                return a.getSeverity() > b.getSeverity();
            });
    }

    //Severity Distribution Map
    void displaySeverityDistribution() const{
        std::map<SeverityLevel, int> distribution;
        
        distribution[SeverityLevel::Low] = 0;
        distribution[SeverityLevel::Medium] = 0;
        distribution[SeverityLevel::High] = 0;
        distribution[SeverityLevel::Critical] = 0;
        
        for(const auto& reading : readings) {
            distribution[reading.getSeverity()]++;
        }

        std::cout << "\nSeverity Distribution:\n";
        for (auto severe : {SeverityLevel::Low, SeverityLevel::Medium, SeverityLevel::High, SeverityLevel::Critical}) {
            std::cout << severityToString(severe) << ": " << distribution[severe] << std::endl;
        }
    }

    //Sensor Lookup
    SensorReading* findReadingByName(const std::string& name) {
        for(auto& reading : readings) {
            if(reading.getSensorName() == name) {
                return &reading;
            }
        }
        return nullptr;
    }
};

int main() {
    DiagnosticReport report;

    report.addReading(SensorReading("EngineTemp", 105, SeverityLevel::High));
    report.addReading(SensorReading("OilPressure", 20, SeverityLevel::Medium));
    report.addReading(SensorReading("BrakeFluidLevel", 5, SeverityLevel::Critical));
    report.addReading(SensorReading("BatteryVoltage", 12.5, SeverityLevel::Low));

    std::cout << "Vehicle Diagnostic Report\n" << std::endl;
    report.displayAllReadings();
    std::cout << std::endl;

    int highOrCriticalCount = report.countSeverityOrHigher(SeverityLevel::High);
    std::cout << "Number of readings with High or Critical severity: "<< highOrCriticalCount<<std::endl;

    // Additional Tasks
    report.displaySeverityDistribution();

    report.sortBySeverityDescending();
    std::cout << "Readings after sorted by Severity" << std::endl;
    report.displayAllReadings();
    std::cout << std::endl;

    //Filter and display only Critical readings
    std::cout << "Critical Severity Readings" << std::endl;
    auto criticalReadings = report.filterBySeverity(SeverityLevel::Critical);
    if (!criticalReadings.empty()) {
        for(const auto& reading : criticalReadings) {
            reading.displayReading();
        }
    } else {
        std::cout << "No Critical severity readings found." << std::endl;
    }
    std::cout << std::endl;

    //Search for a specific sensor and display its details
    std::string searchSensor = "BrakeFluidLevel";
    SensorReading* foundReading = report.findReadingByName(searchSensor);
    if(foundReading != nullptr) {
        std::cout << "Sensor found: ";
        foundReading->displayReading();
    }else{
        std::cout << "Sensor '" << searchSensor << "' not found." << std::endl;
    }
    std::cout << std::endl;

    return 0;
}