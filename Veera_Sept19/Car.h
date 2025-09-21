#ifndef CAR_H
#define CAR_H

#include<string>
#include "ServiceRecord.h"

class Car{
    private:
    std::string vin_;
    std::string make_;
    std::string model_;
    double price_;
    ServiceRecord* serviceHistory_;
    size_t serviceCount_;
    size_t serviceCap_;
    int* damageCodes_;
    size_t damageCount_;
    size_t damageCap_;
    static size_t totalCars_;

    void reserveService(size_t newCap);
    void reserveDamage(size_t newCap);

    public:
    //constructors
    Car();
    Car(const std::string &vin, const std::string &make, const std::string &model, double price);
    Car(const Car &other);

    //destructor
    ~Car();

    //assignment operator
    Car& operator = (Car other);

    friend void swap(Car& lhs, Car& rhs) noexcept;
    
    static size_t getTotalCars();
    
    void setVIN(const std::string& vin);
    void setMake(const std::string& make);
    void setModel(const std::string& model);
    void setPrice(double price);
    
    const std::string& getVIN() const;
    const std::string& getMake() const;
    const std::string& getModel() const;
    double getPrice() const;
    size_t getServiceCount() const;
    size_t getDamageCount() const;
    const ServiceRecord* getServiceHistory() const;
    const int* getDamageCodes() const;
    
    void addService(const ServiceRecord& rec);
    void addDamageCode(int code);
    void printInfo() const;

};




#endif