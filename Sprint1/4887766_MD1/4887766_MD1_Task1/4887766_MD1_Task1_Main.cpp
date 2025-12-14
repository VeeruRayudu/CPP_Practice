#include<iostream>
#include<string>
#include "4887766_MD1_Task1_FleetVehicle.h"
#include<vector>

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
                        refuelVehicle(v, fuel);
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