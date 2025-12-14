#include <iostream>
#include <memory>
#include <functional>
#include <vector>

class Vehicle{
    private:
    std::string m_id;
    float m_mileage;
    bool m_isCommercial;

    public:
    //constructor
    Vehicle(std::string id_, float mileage_, bool isCommercial_) : m_id(id_), m_mileage(mileage_), m_isCommercial(isCommercial_) {}

    void display() const{
        std::cout<<"ID: "<<m_id<<", mileage "<<m_mileage<<", isCommercial: "<<(m_isCommercial ? "Yes" : "No")<<std::endl;
    }

    float getMileage() const { return m_mileage;}
    bool getIsCommercial() const { return m_isCommercial;}
};


int main(){
    //type aliases
    using VehiclePtr = std::shared_ptr<Vehicle>;
    using MaintenanceRule = std::function<void(const Vehicle&)>;

    //creating vehicle object using shared pointer
    VehiclePtr v1 = std::make_shared<Vehicle>("MH12AB1234", 16000, false);

    VehiclePtr v2 = std::make_shared<Vehicle>("MH14XY5678", 9500, true);

    VehiclePtr v3 = std::make_shared<Vehicle>("MH01EV9999", 10500, true);

    //storing the objects in a vector
    std::vector<VehiclePtr> vehicles = {v1, v2, v3};

    //maintenance rule1
    auto rule1 = [](const Vehicle& v){
        if(v.getMileage() > 15000){
            v.display();
            std::cout<<"Rule 1 triggered"<<std::endl;
        }
    };

    //maintenance rule2
    auto rule2 = [](const Vehicle& v){
        if(v.getIsCommercial() && (v.getMileage() > 10000)){
            v.display();
            std::cout<<"Rule 2 triggered"<<std::endl;
        }
    };

    //storing rules in a vector
    std::vector<MaintenanceRule> rules = {rule1, rule2};

    //applying rules to vehicles
    for(auto& v : vehicles){
        for(auto& r : rules){
            r(*v);
        }
    }

    return 0;
}