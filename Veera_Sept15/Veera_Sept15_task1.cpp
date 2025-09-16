#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>

class FleetVehicle{
    private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status;
    bool isAvailable;
    std::string driverName;

    public:
    FleetVehicle(): vehicleID(0), fuelLevel(50.0), distanceTravelled(0.0), status('A'), isAvailable(true), driverName("Unassigned"){}

    FleetVehicle(int vID, float fLevel, double distT, char stat, bool isAvail, std::string dName): vehicleID(vID), fuelLevel(fLevel), distanceTravelled(distT), status(stat), isAvailable(isAvail), driverName(dName){}

    ~FleetVehicle(){
        std::cout << "Destructor called for VehicleID: "<<vehicleID<<std::endl;
    }

    int getVehicleID(){ return vehicleID; }
    float getFuelLevel(){ return fuelLevel; }
    double getDistanceTravelled() {return distanceTravelled;}
    char getStatus() {return status;}
    bool getIsAvailable() {return isAvailable;}
    std::string getDriverName() {return driverName;}

    void setVehicleID(int vID){
        vehicleID = vID;
    }
    void setFuelLevel(float fLevel){
        fuelLevel = fLevel;
    }
    void setDistanceTravelled(double distT){
        distanceTravelled = distT;
    }
    void setStatus(char stat){
        status =stat;
    }
    void setIsAvailable(bool isAvail){
        isAvailable = isAvail;
    }
    void setDriverName(std::string dName){
        driverName = dName;
    }

    void updateStatus(){
        if(fuelLevel < 10.0 || !isAvailable){
            status = 'I';
        }else{
            status = 'A';
        }
    }

    void displayInfo(){
        std::cout <<"\n--------Vehicle Information-----------------";
        std::cout <<"Vehicle ID: "<<vehicleID<<std::endl;
        std::cout <<"Fuel Level: "<<fuelLevel<<std::endl;
        std::cout <<"Distance Travelled: "<<distanceTravelled<<std::endl;
        std::cout <<"Status: "<<(status == 'A' ? "Active" : "Inactive" )<<std::endl;
        std::cout <<"Available: "<<(isAvailable ? "yes" : "No")<<std::endl;
        std::cout <<"Driver Name: "<<driverName<<std::endl;
    }
};

void assignDriver(FleetVehicle &vehicle, std::string dName){
    vehicle.setDriverName(dName);
    std::cout <<"Driver "<<vehicle.getDriverName() <<"has been to vehicle ID "<<vehicle.getVehicleID()<<std::endl;
}

void refuelVehicle(FleetVehicle &vehicle, float fLevel){
    if(fLevel <=0 ){
        throw std::invalid_argument("Fuel Level should be greater than Zero");
    }
    float newLevel = vehicle.getFuelLevel() + fLevel;
    std::cout <<"Vehicle ID "<<vehicle.getVehicleID()<<" refueled by "<<fLevel<<". Current fuel "<<newLevel<<std::endl;
}

int main(){
    std::vector<FleetVehicle> fleet;
        fleet.emplace_back(101, 45.5f, 120.0, 'A', true, "Raj");
        fleet.emplace_back(102, 8.0f, 300.0f, 'A', true, "Priya");
        fleet.emplace_back();

    int choice;
    do{
        std::cout<<"\n-------------Fleet Monitoring System------------------\n";
        std::cout<<"1. Add vehicle details\n";
        std::cout<<"2. Assign Driver\n";
        std::cout<<"3. Refuel Vehicle\n";
        std::cout<<"4. Update Status\n";
        std::cout<<"5. Display Vehicle Information\n";
        std::cout<<"6. Exit\n";
        std::cout<<"Enter your choice: ";
        std::cin >> choice;
        
        switch(choice){
            case 1:{
                int id; float fuel;
                double dist;
                bool isAvail;
                char stat;
                std::string dName;
                std::cout<<"Enter Vehicle ID: "; std::cin>>id;
                std::cout<< "Enter fuel level: "; std::cin>>fuel;
                std::cout<< "Enter distance travelled: "; std::cin>>dist;
                std::cout<< "Enter status (A for Active/ I for inactive)"; std::cin>>stat;
                std::cout<< "Is Available (1 for yes/ 0 for no): "; std::cin>>isAvail;
                std::cin.ignore();
                std::cout<< "Enter Driver Name: "; std::cin>>dName;

                fleet.emplace_back(id, fuel, dist, stat, isAvail, dName);
                break;
            }
            case 2:{
                int id;
                std::string dName;
                std::cout<<"Enter Vehicle ID: "; std::cin>>id;
                std::cin.ignore();

                bool found = false;
                for(auto &v : fleet){
                    if(v.getVehicleID() == id){
                        found = true;
                        std::cout<<"Enter Driver Name: "; std::cin>>dName;
                        assignDriver(v, dName);
                    }
                    break;
                }
                if(!found){
                    std::cout<<"Vehicle not found\n";
                }
                break;

            }
            case 3:{
                int id;
                float fuel;
                std::cout<<"Enter vehicle id: "; std::cin>>id;
                bool found = false;
                for(auto &v : fleet){
                    if(v.getVehicleID() == id){
                        
                        std::cout<<"Enter Fuel Level: "; std::cin>>fuel;
                        try{
                            refuelVehicle(v, fuel);
                        }catch(std::exception &e){
                            std::cout<<"Error!"<<e.what()<<std::endl;
                        }
                        found = true;
                        break;
                    }
                }
                if(!found){
                    std::cout<<"Vehicle not found\n";
                }
                break;
            }
            case 4:{
                int id;
                std::cout<<"Enter Vehicle ID: "; std::cin>>id;
                bool found = false;
                for(auto &v : fleet){
                    if(v.getVehicleID() == id){
                        v.updateStatus();
                        std::cout<<"Status for vehicle id: "; std::cin>>id;
                        found = true;
                        break;
                    }
                    
                }
                if(!found){
                    std::cout<<"Vehicle not found\n";
                }
                break;
            }
            case 5: {
                 int id;
                std::cout<<"Enter Vehicle ID: "; std::cin>>id;
                bool found = false;
                for(auto &v : fleet){
                    if(v.getVehicleID() == id){
                        v.displayInfo();
                        found = true;
                        break;
                    }
                }
                if(!found){
                    std::cout<<"Vehicle not found\n";
                }
                break;
            }
            case 6:{
                std::cout<<"Exiting the program\n";
                break;
                default:
                std::cout<<"Invalid choice!\n" ;

            }

        }
    }while(choice!=6);
    return 0;
}