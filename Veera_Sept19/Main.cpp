#include <iostream>
#include "Car.h"
#include "ServiceRecord.h"
#include "GlobalFunctions.h"

int main() {
    // Task 1: Print initial static counter value
    std::cout << "Initial car count: " << Car::getTotalCars() << std::endl;
    
    // Task 2: Default-construct a Car object
    Car cDefault;
    std::cout << "After default construction, car count: " << Car::getTotalCars() << std::endl;
    cDefault.printInfo();
    
    // Task 3: Parameter-construct a Car
    Car cParam("1HGCM", "Honda", "Accord", 19999.99);
    std::cout << "After parameter construction, car count: " << Car::getTotalCars() << std::endl;
    cParam.printInfo();
    
    // Task 4: Add damage codes
    cParam.addDamageCode(101);
    cParam.addDamageCode(205);
    cParam.addDamageCode(307);
    std::cout << "After adding damage codes:" << std::endl;
    cParam.printInfo();
    
    // Task 5: Create and add service records
    ServiceRecord sr1("2022-03-15", 15000, "Oil change");
    ServiceRecord sr2("2023-01-10", 25000, "Brake pads replacement");
    
    cParam.addService(sr1);
    cParam.addService(sr2);
    std::cout << "After adding service records:" << std::endl;
    cParam.printInfo();
    
    // Task 6: Copy-construct a new Car
    Car cCopy(cParam);
    std::cout << "After copy construction, car count: " << Car::getTotalCars() << std::endl;
    
    // Task 6a: Display and modify damage codes
    std::cout << "Original car damage codes: ";
    const int* origCodes = cParam.getDamageCodes();
    for (size_t i = 0; i < cParam.getDamageCount(); i++) {
        std::cout << origCodes[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copy car damage codes: ";
    const int* copyCodes = cCopy.getDamageCodes();
    for (size_t i = 0; i < cCopy.getDamageCount(); i++) {
        std::cout << copyCodes[i] << " ";
    }
    std::cout << std::endl;
    
    // Task 6b: Query service count
    std::cout << "Original service count: " << cParam.getServiceCount() << std::endl;
    std::cout << "Copy service count: " << cCopy.getServiceCount() << std::endl;
    
    // Task 7: Default-construct and assign
    Car cAssign;
    cAssign = cParam;
    std::cout << "After assignment, car count: " << Car::getTotalCars() << std::endl;
    
    // Task 8: Allocate dynamic array of 3 Car objects
    const size_t N = 3;
    Car* garage = new Car[N];
    std::cout << "After dynamic allocation, car count: " << Car::getTotalCars() << std::endl;
    
    // Task 8a: Initialize each element
    garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
    garage[1] = Car("5YJ3E", "Tesla", "Model 3", 39999.00);
    garage[2] = Car("WBA4", "BMW", "3 Series", 34999.99);
    
    // Task 8b: Add damage codes and service records using a lambda
    auto initCar = [](Car& car, const int* codes, size_t codeCount, 
                     const ServiceRecord* records, size_t recordCount) {
        for (size_t i = 0; i < codeCount; i++) {
            car.addDamageCode(codes[i]);
        }
        for (size_t i = 0; i < recordCount; i++) {
            car.addService(records[i]);
        }
    };
    
    int damageAcura[] = {102, 208};
    ServiceRecord recordsAcura[] = {
        ServiceRecord("2022-05-20", 12000, "Oil change"),
        ServiceRecord("2023-02-15", 22000, "Tire rotation")
    };
    
    int damageTesla[] = {110, 220, 330, 440};
    ServiceRecord recordsTesla[] = {
        ServiceRecord("2022-08-10", 10000, "Software update"),
        ServiceRecord("2023-04-05", 20000, "Battery check")
    };
    
    int damageBMW[] = {150, 250};
    ServiceRecord recordsBMW[] = {
        ServiceRecord("2022-06-15", 15000, "Oil change"),
        ServiceRecord("2023-01-20", 25000, "Brake service")
    };
    
    initCar(garage[0], damageAcura, 2, recordsAcura, 2);
    initCar(garage[1], damageTesla, 4, recordsTesla, 2);
    initCar(garage[2], damageBMW, 2, recordsBMW, 2);
    
    // Task 8c: Print all cars
    std::cout << "All cars in garage:" << std::endl;
    for (size_t i = 0; i < N; i++) {
        garage[i].printInfo();
        std::cout << std::endl;
    }
    
    // Task 9: Calculate average price
    double avg = averagePrice(garage, N);
    std::cout << "Average price: $" << avg << std::endl;
    
    // Task 10: Call global utilities
    const Car* mostExpensive = maxPriceCar(garage, N);
    std::cout << "Most expensive car: ";
    mostExpensive->printInfo();
    
    const Car* foundCar = findCarByVIN(garage, N, "5YJ3E");
    if (foundCar) {
        std::cout << "Found car with VIN 5YJ3E: ";
        foundCar->printInfo();
    }
    
    size_t carsWithDamage = countCarsWithDamage(garage, N, 102);
    std::cout << "Cars with damage code 102: " << carsWithDamage << std::endl;
    
    bool areEqual = areCarsEqual(garage[0], garage[1]);
    std::cout << "Are first two cars equal? " << (areEqual ? "Yes" : "No") << std::endl;
    
    // Task 11: Delete the heap array
    delete[] garage;
    std::cout << "After deleting dynamic array, car count: " << Car::getTotalCars() << std::endl;
    
    // Task 12: Attempt to modify a const Car& 
    const Car& constCar = cParam;
    // constCar.setPrice(10000); // This would cause a compilation error
    
    // Task 13: Print final static counter value
    std::cout << "Final car count: " << Car::getTotalCars() << std::endl;
    
    return 0;
}