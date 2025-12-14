#include <iostream>
#include <functional>
#include <array>

double fuelConsumptionEstimator(int rpm){
    return rpm/100.0;
}

double engineStressIndex(int rpm){
    return rpm % 1200;
}

double ecoScore(int rpm){
    return 5000 - rpm;
}

void analyzer(std::array<int,5> arr, std::function<double(int)> analyze){
    for(int i=0; i<arr.size(); i++){
        std::cout<<analyze(arr[i])<<" ";
    }
}

int main(){
    int choice;
    std::cout<<"Enter choice: \n1 for Fuel Consumption Estimator. \n2 for Engine Stress Index. \n3 for Eco Score."<<std::endl;
    std::cin>>choice;

    std::array<int, 5> rpm = {1000, 1500, 2000, 2500, 3000};

    std::function<double(int)> analysis;

    switch (choice)
    {
    case 1 : analysis = fuelConsumptionEstimator;
        break;
        
    case 2 : analysis = engineStressIndex;
        break;

    case 3 : analysis = ecoScore;
        break;
    
    default: std::cerr<<"Invalid choice\n";
        break;
    }
    analyzer(rpm, analysis);

    return 0;
}

