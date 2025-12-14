#include <iostream>

class Vehicle{
    private:
    std::string m_make;
    std::string m_model;
    int m_yearOfManufacturing;
    double m_exShowRoomPrice;

    public:
    Vehicle(){
        this->m_make="Tata";
        this->m_model="Nexon";
        this->m_yearOfManufacturing=2024;
        this->m_exShowRoomPrice=12.56;
    }

    Vehicle(std::string make_, std::string model_, int yearOfManufacturing_, double exShowRoomPrice_){
        m_make = make_;
        m_model = model_;
        m_yearOfManufacturing = yearOfManufacturing_;
        m_exShowRoomPrice = exShowRoomPrice_;
    }

    //getters
    std::string getMake(){
        return m_make;
    }
    std::string getModel(){
        return m_model;
    }
    int getYearOfManufacturing(){
        return m_yearOfManufacturing;
    }
    double getExShowroowPrice(){
        return m_exShowRoomPrice;
    }

    //setters
    void setMake(std::string make_){
        this->m_make = make_;
    }
    void setModel(std::string model_){
        this->m_model = model_;
    }
    void setYearOfManufacturing(int yearOfManufacturing_){
        this->m_yearOfManufacturing = yearOfManufacturing_;
    }
    void setExShowroomPrice(double exShowroomPrice_){
        this->m_exShowRoomPrice = exShowroomPrice_;
    }

    void display(){
        std::cout<<"Make: "<<m_make<<", Model: "<<m_model<<", Year of Manufacturing: "<<m_yearOfManufacturing<<", Ex Showroom Price: "<<m_exShowRoomPrice<<"\n";
    }
    
};

int main(){
    Vehicle vehicles[3] ={
        Vehicle(),
        Vehicle("Toyota", "Fortuner", 2024, 13.5),
        Vehicle("Hyundai", "Creta", 2022, 11.4)
    };

    for(int i=0;i<3;i++){
        vehicles[i].display();
    }
    
}