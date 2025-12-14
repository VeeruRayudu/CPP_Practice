#ifndef SAFETYFEATURE_H
#define SAFETYFEATURE_H
#include <iostream>
#include <string>

class SafetyFeature{
    protected:
    std::string m_featureName;
    bool m_isEnabled;

    public:
    //constructor
    SafetyFeature();
    SafetyFeature(std::string feature, bool isEnabled);

    //delete copy constructor
    SafetyFeature(SafetyFeature& other) = delete;

    //activate function
    virtual void activate();
};

class Airbag: public SafetyFeature{
    private:
    int m_deploymentThreshold;

    public:
    Airbag(std::string feature, bool isEnabled, int threshold);
    void activate() override;
};

class ABS: public SafetyFeature{
    private:
    double m_wheelSpeedSensorAccuracy;

    public:
    ABS(std::string feature, bool isEnabled, double accuracy);
    void activate() override;
};

#endif