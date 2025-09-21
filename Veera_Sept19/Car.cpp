#include "Car.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

size_t Car::totalCars_ = 0;

Car::Car() 
    : vin_(""), make_(""), model_(""), price_(0.0),
      serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
      damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
    totalCars_++;
}

Car::Car(const std::string& vin, const std::string& make, const std::string& model, double price) 
    : vin_(vin), make_(make), model_(model), price_(price),
      serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
      damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
    if (price < 0) {
        throw std::invalid_argument("Price must be non-negative");
    }
    totalCars_++;
}

Car::Car(const Car& other) 
    : vin_(other.vin_), make_(other.make_), model_(other.model_), price_(other.price_),
      serviceCount_(other.serviceCount_), serviceCap_(other.serviceCap_),
      damageCount_(other.damageCount_), damageCap_(other.damageCap_) {
    
    // Deep copy service history (shallow copy of ServiceRecord objects)
    serviceHistory_ = new ServiceRecord[serviceCap_];
    for (size_t i = 0; i < serviceCount_; i++) {
        serviceHistory_[i] = other.serviceHistory_[i];
    }
    
    // Deep copy damage codes
    damageCodes_ = new int[damageCap_];
    for (size_t i = 0; i < damageCount_; i++) {
        damageCodes_[i] = other.damageCodes_[i];
    }
    
    totalCars_++;
}

Car::~Car() {
    delete[] serviceHistory_;
    delete[] damageCodes_;
    totalCars_--;
}

void swap(Car& lhs, Car& rhs) noexcept {
    using std::swap;
    swap(lhs.vin_, rhs.vin_);
    swap(lhs.make_, rhs.make_);
    swap(lhs.model_, rhs.model_);
    swap(lhs.price_, rhs.price_);
    swap(lhs.serviceHistory_, rhs.serviceHistory_);
    swap(lhs.serviceCount_, rhs.serviceCount_);
    swap(lhs.serviceCap_, rhs.serviceCap_);
    swap(lhs.damageCodes_, rhs.damageCodes_);
    swap(lhs.damageCount_, rhs.damageCount_);
    swap(lhs.damageCap_, rhs.damageCap_);
}

Car& Car::operator=(Car other) {
    swap(*this, other);
    return *this;
}

size_t Car::getTotalCars() {
    return totalCars_;
}

void Car::setVIN(const std::string& vin) { vin_ = vin; }
void Car::setMake(const std::string& make) { make_ = make; }
void Car::setModel(const std::string& model) { model_ = model; }
void Car::setPrice(double price) { 
    if (price < 0) {
        throw std::invalid_argument("Price must be non-negative");
    }
    price_ = price; 
}

const std::string& Car::getVIN() const { return vin_; }
const std::string& Car::getMake() const { return make_; }
const std::string& Car::getModel() const { return model_; }
double Car::getPrice() const { return price_; }
size_t Car::getServiceCount() const { return serviceCount_; }
size_t Car::getDamageCount() const { return damageCount_; }
const ServiceRecord* Car::getServiceHistory() const { return serviceHistory_; }
const int* Car::getDamageCodes() const { return damageCodes_; }

void Car::reserveService(size_t newCap) {
    if (newCap <= serviceCap_) return;
    
    ServiceRecord* newHistory = new ServiceRecord[newCap];
    for (size_t i = 0; i < serviceCount_; i++) {
        newHistory[i] = serviceHistory_[i];
    }
    
    delete[] serviceHistory_;
    serviceHistory_ = newHistory;
    serviceCap_ = newCap;
}

void Car::reserveDamage(size_t newCap) {
    if (newCap <= damageCap_) return;
    
    int* newCodes = new int[newCap];
    for (size_t i = 0; i < damageCount_; i++) {
        newCodes[i] = damageCodes_[i];
    }
    
    delete[] damageCodes_;
    damageCodes_ = newCodes;
    damageCap_ = newCap;
}

void Car::addService(const ServiceRecord& rec) {
    if (serviceCount_ >= serviceCap_) {
        reserveService(serviceCap_ == 0 ? 2 : serviceCap_ * 2);
    }
    serviceHistory_[serviceCount_++] = rec;
}

void Car::addDamageCode(int code) {
    if (damageCount_ >= damageCap_) {
        reserveDamage(damageCap_ == 0 ? 2 : damageCap_ * 2);
    }
    damageCodes_[damageCount_++] = code;
}

void Car::printInfo() const {
    std::cout << "VIN: " << vin_ 
              << ", Make: " << make_ 
              << ", Model: " << model_ 
              << ", Price: $" << price_
              << ", Services: " << serviceCount_
              << ", Damage Codes: " << damageCount_
              << std::endl;
    
    if (serviceCount_ > 0) {
        std::cout << "Service History:" << std::endl;
        for (size_t i = 0; i < serviceCount_; i++) {
            std::cout << "  ";
            serviceHistory_[i].print();
        }
    }
    
    if (damageCount_ > 0) {
        std::cout << "Damage Codes: ";
        for (size_t i = 0; i < damageCount_; i++) {
            std::cout << damageCodes_[i] << " ";
        }
        std::cout << std::endl;
    }
}