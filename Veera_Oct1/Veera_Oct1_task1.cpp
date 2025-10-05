#include<iostream>
#include<string>
#include<iomanip>

class HybridVehicle{
    private:
    std::string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    int trips[10];
    int tripCount;

    public:
    //constructor
    HybridVehicle(std::string model = "", float electricKm_ = 0, float gasolineKm_ = 0, float gasolineUsed_ = 0){
        modelName = model;
        electricKm = electricKm_;
        gasolineKm = gasolineKm_;
        gasolineUsed = gasolineUsed_;
        tripCount = 0;
        for(int i=0; i<10; i++) trips[i]=0;
    }

    int& operator[](int index){
        if(index>=0 && index<=10){
            if(index>=tripCount) tripCount = index+1;
            return trips[index];
        }
        throw std::out_of_range("index out of range");
    }
    
    int operator()() const{
        return electricKm + gasolineKm;
    }

    operator float() const{
        return (gasolineUsed > 0) ? (gasolineKm/gasolineUsed) : 0;
    }

    HybridVehicle operator+(const HybridVehicle &other){
        HybridVehicle result;
        result.modelName = modelName + "+" + other.modelName;
        result.electricKm = electricKm + other.electricKm;
        result.gasolineKm = gasolineKm + other.gasolineKm;
        result.gasolineUsed = gasolineUsed + other.gasolineUsed;
        result.tripCount = std::min(tripCount+other.tripCount, 10);

        for(int i=0; i<tripCount && i<10; i++) result.trips[i] = trips[i];
        for(int j=0; j<other.tripCount && (j+tripCount)<10; j++) result.trips[j] = other.trips[j];

        return result;
    }

    bool operator==(const HybridVehicle &other){
        return (float)(*this) == (float)other;
    }

    HybridVehicle& operator=(const HybridVehicle &other){
        if(this != &other){
            modelName = other.modelName;
            electricKm = other.electricKm;
            gasolineKm = other.gasolineKm;
            gasolineUsed = other.gasolineUsed;
            tripCount = other.tripCount;
            for(int i=0; i<10; i++) trips[i] = other.trips[i];
        }
        return *this;
    }

    HybridVehicle& operator++(){
        if(tripCount < 10){
            trips[tripCount++] = 10;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const HybridVehicle &v){
        os<<"Model: "<<v.modelName<<"\n";
        os<<"Electric KM: "<<v.electricKm<<" Gasoline KM: "<<v.gasolineKm<<", fuel used "<<v.gasolineUsed<<"L\n";
        os<<"Trips";
        for(int i=0; i<v.tripCount; i++) os<<v.trips[i]<<" ";
        os<<"\nTotal Distance: "<<v()<<"Km\n";
        os<<"Efficiency: "<<(float)v<<"Km/L \n";

        return os;
    }
};

int main() {
    HybridVehicle v1("Prius", 120.5, 80.0, 4.5);
    HybridVehicle v2("Volt", 100.0, 90.0, 5.0);

    v1[0] = 50; v1[1] = 60;
    v2[0] = 70; v2[1] = 40;

    std::cout << "Vehicle 1:\n" << v1 << std::endl;
    std::cout << "Vehicle 2:\n" << v2 << std::endl;

    //Combine
    HybridVehicle v3 = v1 + v2;
    std::cout << "Combined Vehicle:\n" << v3 << std::endl;

    //Compare
    std::cout << "Are v1 and v2 equally efficient? " << ((v1 == v2) ? "Yes" : "No") << std::endl;

    //simulate new trip
    ++v1;
    std::cout << "After new trip, v1:\n" << v1 << std::endl;

    //Access trip
    std::cout << "Trip[1] of v2: " << v2[1] << " km\n";

    //Total distance
    std::cout << "Total distance of v1: " << v1() << " km\n";

    //Efficiency
    std::cout << "Fuel efficiency of v2: " << (float)v2 << " km/L\n";

    //Deep copy
    HybridVehicle v4;
    v4 = v1;
    std::cout << "Copied Vehicle v4:\n" << v4 << std::endl;

    return 0;
}
