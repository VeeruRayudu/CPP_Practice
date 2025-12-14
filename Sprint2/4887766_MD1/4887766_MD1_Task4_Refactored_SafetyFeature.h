#ifndef SAFETYFEATURE_H
#define SAFETYFEATURE_H

#include <iostream>
#include <string>

class SafetyFeature {
protected:
    std::string m_featureName;
    bool m_isEnabled;

public:
    SafetyFeature();
    explicit SafetyFeature(const std::string& feature, bool isEnabled);

    // Prevent copying
    SafetyFeature(const SafetyFeature& other) = delete;

    // Ensure proper cleanup in derived classes
    virtual ~SafetyFeature() = default;

    virtual void activate();
};

class Airbag : public SafetyFeature {
private:
    int m_deploymentThreshold;

public:
    explicit Airbag(const std::string& feature, bool isEnabled, int threshold);
    void activate() override;
};

class ABS : public SafetyFeature {
private:
    double m_wheelSpeedSensorAccuracy;

public:
    explicit ABS(const std::string& feature, bool isEnabled, double accuracy);
    void activate() override;
};

#endif // SAFETYFEATURE_H