#include <iostream>
#include <string>
#include <vector>

//Enum Class SeverityLevel
enum class SeverityLevel {
    Low,
    Medium,
    High,
    Critical
};

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

    return 0;
}