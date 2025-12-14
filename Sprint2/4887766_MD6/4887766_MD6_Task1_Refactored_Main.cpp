#include <iostream>
#include <functional>
#include <array>

// Analysis functions
double fuelConsumptionEstimator(int rpm) {
    return rpm / 100.0;
}

double engineStressIndex(int rpm) {
    return rpm % 1200;
}

double ecoScore(int rpm) {
    return 5000 - rpm;
}

// Analyzer utility
void analyzeRPMs(const std::array<int, 5>& rpms, const std::function<double(int)>& analysisFn) {
    for (int rpm : rpms) {
        std::cout << analysisFn(rpm) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::array<int, 5> rpmValues = {1000, 1500, 2000, 2500, 3000};

    std::cout << "Select analysis type:\n"
              << "1 - Fuel Consumption Estimator\n"
              << "2 - Engine Stress Index\n"
              << "3 - Eco Score\n"
              << "Choice: ";

    int choice;
    std::cin >> choice;

    std::function<double(int)> analysisFn;

    switch (choice) {
        case 1:
            analysisFn = fuelConsumptionEstimator;
            break;
        case 2:
            analysisFn = engineStressIndex;
            break;
        case 3:
            analysisFn = ecoScore;
            break;
        default:
            std::cerr << "Invalid choice\n";
            return 1;
    }

    analyzeRPMs(rpmValues, analysisFn);
    return 0;
}