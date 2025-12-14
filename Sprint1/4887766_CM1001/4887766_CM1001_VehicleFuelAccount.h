#ifndef VEHICLEFUELACCOUNT_H
#define VEHICLEFUELACCOUNT_H

class VehicleFuelAccount{
    private:
    double m_fuelBalance;
    static double m_fleetEfficiencyRate;

    public:
    //constructor
    VehicleFuelAccount(double fuelBalance_);
    ~VehicleFuelAccount();

    //utiltiy methods
    void calculateMonthlyBonus();
    static void modifyEfficiencyRate(double newRate);
    void display();

    //getter
    double getFuelBalance() const;
};

void applyBonusToFleet(VehicleFuelAccount* arr[], int size);
double getTotalFleetFuel(VehicleFuelAccount* arr[], int size);

#endif