#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include "Car.h"

double averagePrice(const Car* arr, size_t n);
bool compareByPriceAsc(const Car& a, const Car& b);
bool compareByPriceDesc(const Car& a, const Car& b);
bool areCarsEqual(const Car& a, const Car& b);
const Car* maxPriceCar(const Car* arr, size_t n);
const Car* findCarByVIN(const Car* arr, size_t n, const std::string& vin);
size_t countCarsWithDamage(const Car* arr, size_t n, int code);
void swapCars(Car& a, Car& b);

#endif 