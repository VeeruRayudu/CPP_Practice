#include "4887766_MD1_Task4_SafetyFeature.h"

//constructor initialization
SafetyFeature::SafetyFeature() = default;

SafetyFeature::SafetyFeature(std::string feature, bool isEnabled): m_featureName(feature), m_isEnabled(isEnabled){};

//activate function - base
void SafetyFeature::activate(){
    std::cout<<"Activating generic safety feature"<<"\n";
}

Airbag::Airbag(std::string feature, bool isEnabled, int threshold): SafetyFeature(feature, isEnabled), m_deploymentThreshold(threshold) {};

//activate function - airbag 
void Airbag::activate(){
    std::cout<<"Activating airbag safety feature"<<"\n";
}

ABS::ABS(std::string feature, bool isEnabled, double accuracy): SafetyFeature(feature, isEnabled), m_wheelSpeedSensorAccuracy(accuracy){};

//activate function - ABS
void ABS::activate(){
    std::cout<<"Activating ABS safety feature"<<"\n";
}

