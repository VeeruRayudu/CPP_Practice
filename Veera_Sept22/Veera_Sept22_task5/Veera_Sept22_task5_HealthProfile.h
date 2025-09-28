#include<string>

class HealthProfile{
    private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int dobDay;
    int dobMonth;
    int dobYear;
    int height;
    int weight;

    public:

    //constructor
    HealthProfile(std::string fName, std::string lName, std::string gender_, int day, int month, int year, int height_, int weight_);

    //setters
    void setFirstName(const std::string fName);
    void setLastName(const std::string lName);
    void setGender(const std::string gender_);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setHeight(int height_);
    void setWeight(int weight_);

    //getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGender() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getHeight() const;
    int getWeight() const;

    int getAge();

    int getMaximumHeartRate(int age);

    void getTargetHeartRate(int maxHeartRate, double lower, double upper);

    double getBMI(int age);


};