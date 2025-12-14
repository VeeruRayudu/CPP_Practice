#include "4887766_MD1_Task4_Refactored_SafetyFeature.h"

// ─── SafetyFeature Base Class ─────────────────────────────────────────

SafetyFeature::SafetyFeature() = default;

SafetyFeature::SafetyFeature(const std::string& feature, bool isEnabled)
    : m_featureName(feature), m_isEnabled(isEnabled) {}

void SafetyFeature::activate() {
    std::cout << "Activating generic safety feature" << std::endl;
}

// ─── Airbag Derived Class ────────────────────────────────────────────

Airbag::Airbag(const std::string& feature, bool isEnabled, int threshold)
    : SafetyFeature(feature, isEnabled), m_deploymentThreshold(threshold) {}

void Airbag::activate() {
    std::cout << "Activating airbag safety feature" << std::endl;
}

// ─── ABS Derived Class ───────────────────────────────────────────────

ABS::ABS(const std::string& feature, bool isEnabled, double accuracy)
    : SafetyFeature(feature, isEnabled), m_wheelSpeedSensorAccuracy(accuracy) {}

void ABS::activate() {
    std::cout << "Activating ABS safety feature" << std::endl;
}