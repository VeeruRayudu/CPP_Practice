#include<iostream>
#include<cstdint>
#include<limits>

class Pedestrian{
    private:
    uint32_t pedestrianID;
    float distanceFromVehicle;

    public:
    Pedestrian(): pedestrianID(0U), distanceFromVehicle(0.0f){}
    Pedestrian(uint32_t _pedestrianID, float _distanceFromVehicle) : pedestrianID(_pedestrianID), distanceFromVehicle(_distanceFromVehicle){}

    void updateDistance(float newDistance){
        distanceFromVehicle = newDistance;
    }

    float getDistance() const {
        return distanceFromVehicle;
    }

    uint32_t getPedestrianID() const {
        return pedestrianID;
    }

};

void findClosestPedestrian(Pedestrian *array, uint32_t size, const Pedestrian* &closest){
    float dist = std::numeric_limits<float>::max();
    for(uint32_t i=0;i<size;i++){
        if(array[i].getDistance() < dist){
            dist = array[i].getDistance();
            closest = &array[i];
         }
    }
}

void printPedestrianInfo(const Pedestrian &ped){
    
    std::cout<<"Pedestrian ID: "<<ped.getPedestrianID()<<" Pedestrian Distance from Vehicle: "<<ped.getDistance()<<std::endl;
}

void printClosestPedestrian(const Pedestrian *closest){
    if(closest!=nullptr){
        std::cout<<"\n------Closest Pedestrian detected----------\n";
        printPedestrianInfo(*closest);
    }else{
        std::cout<<"\n No Pedestrian Detected";
    }
    
}

int main(){
    uint32_t numberOfPedestrians = 3U;
    Pedestrian *pedestrianArray = new Pedestrian[numberOfPedestrians]
    {
        Pedestrian(101U, 12.4f),
        Pedestrian(102U, 8.7f),
        Pedestrian(103U, 15.1f)
    };

    const Pedestrian *closest = nullptr;
    findClosestPedestrian(pedestrianArray, numberOfPedestrians, closest);  

    std::cout<<"\n -----All Pedestrians Info------\n";
    for(uint32_t i=0U;i<numberOfPedestrians;i++){
        printPedestrianInfo(pedestrianArray[i]);
    }

    printClosestPedestrian(closest);

    delete pedestrianArray;
    pedestrianArray = nullptr;

    return 0;
}

