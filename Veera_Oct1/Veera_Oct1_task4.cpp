#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <iomanip>

class Student {
protected:
    std::string name;
    std::string studentID;
    std::string department;

public:
    //Constructor
    Student(const std::string& n, const std::string& id, const std::string& dept)
        : name(n), studentID(id), department(dept) {}

    virtual ~Student() {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << "\n" << "ID: " << studentID << "\n"<< "Department: " << department << std::endl;
    }

    virtual std::string getLevel() const {
        return "Student";
    }

    //Getters
    std::string getName() const { return name; }
    std::string getID() const { return studentID; }
    std::string getDepartment() const { return department; }
};

class UndergraduateStudent : public Student {
protected:
    int year;
    int creditsEarned;

public:
    UndergraduateStudent(const std::string& n, const std::string& id, const std::string& dept, int y, int credits): Student(n, id, dept), year(y), creditsEarned(credits) {}

    void displayInfo() const override {
        Student::displayInfo();
        std::cout << "Year: " << year << "\n"<< "Credits Earned: " << creditsEarned << std::endl;
    }

    std::string getLevel() const override {
        return "Undergraduate Student";
    }
};

class Freshman : public UndergraduateStudent {
public:
    Freshman(const std::string& n, const std::string& id, 
             const std::string& dept, int y, int credits) : UndergraduateStudent(n, id, dept, y, credits) {}

    void displayInfo() const override {
        UndergraduateStudent::displayInfo();
        std::cout << "Status: First Year Undergraduate" << std::endl;
    }

    std::string getLevel() const override {
        return "Freshman";
    }
};

class Sophomore : public UndergraduateStudent {
public:
    Sophomore(const std::string& n, const std::string& id, 
              const std::string& dept, int y, int credits)
        : UndergraduateStudent(n, id, dept, y, credits) {}

    void displayInfo() const override {
        UndergraduateStudent::displayInfo();
        std::cout << "Status: Second Year Undergraduate" << std::endl;
    }

    std::string getLevel() const override {
        return "Sophomore";
    }
};

class Junior : public UndergraduateStudent {
public:
    Junior(const std::string& n, const std::string& id, 
           const std::string& dept, int y, int credits)
        : UndergraduateStudent(n, id, dept, y, credits) {}

    void displayInfo() const override {
        UndergraduateStudent::displayInfo();
        std::cout << "Status: Third Year Undergraduate" << std::endl;
    }

    std::string getLevel() const override {
        return "Junior";
    }
};

class Senior : public UndergraduateStudent {
public:
    Senior(const std::string& n, const std::string& id, 
           const std::string& dept, int y, int credits)
        : UndergraduateStudent(n, id, dept, y, credits) {}

    void displayInfo() const override {
        UndergraduateStudent::displayInfo();
        std::cout << "Status: Fourth Year Undergraduate" << std::endl;
    }

    std::string getLevel() const override {
        return "Senior";
    }
};

class HonorsSenior : public Senior {
private:
    std::string thesisTitle;

public:
    HonorsSenior(const std::string& n, const std::string& id, 
                 const std::string& dept, int y, int credits, 
                 const std::string& thesis)
        : Senior(n, id, dept, y, credits), thesisTitle(thesis) {}

    void displayInfo() const override {
        Senior::displayInfo();
        std::cout << "Honors Thesis: " << thesisTitle << "\n"
                  << "Status: Honors Program Senior" << std::endl;
    }

    std::string getLevel() const override {
        return "Honors Senior";
    }
};

class ExchangeSenior : public Senior {
private:
    std::string homeUniversity;

public:
    ExchangeSenior(const std::string& n, const std::string& id, 
                   const std::string& dept, int y, int credits, 
                   const std::string& homeUni)
        : Senior(n, id, dept, y, credits), homeUniversity(homeUni) {}

    void displayInfo() const override {
        Senior::displayInfo();
        std::cout << "Home University: " << homeUniversity << "\n"
                  << "Status: Exchange Program Senior" << std::endl;
    }

    std::string getLevel() const override {
        return "Exchange Senior";
    }
};

//Graduate Student Hierarchy
class GraduateStudent : public Student {
protected:
    std::string advisor;

public:
    GraduateStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv)
        : Student(n, id, dept), advisor(adv) {}

    void displayInfo() const override {
        Student::displayInfo();
        std::cout << "Advisor: " << advisor << std::endl;
    }

    std::string getLevel() const override {
        return "Graduate Student";
    }
};

class MastersStudent : public GraduateStudent {
public:
    MastersStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv)
        : GraduateStudent(n, id, dept, adv) {}

    void displayInfo() const override {
        GraduateStudent::displayInfo();
        std::cout << "Program: Master's Degree" << std::endl;
    }

    std::string getLevel() const override {
        return "Masters Student";
    }
};

class ThesisMastersStudent : public MastersStudent {
private:
    std::string thesisTitle;

public:
    ThesisMastersStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& thesis) : MastersStudent(n, id, dept, adv), thesisTitle(thesis) {}

    void displayInfo() const override {
        MastersStudent::displayInfo();
        std::cout << "Thesis Title: " << thesisTitle << "\n"<< "Program: Thesis-based Master's" << std::endl;
    }

    std::string getLevel() const override {
        return "Thesis Masters Student";
    }
};

class NonThesisMastersStudent : public MastersStudent {
private:
    std::string projectTitle;

public:
    NonThesisMastersStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& project) : MastersStudent(n, id, dept, adv), projectTitle(project) {}

    void displayInfo() const override {
        MastersStudent::displayInfo();
        std::cout << "Project Title: " << projectTitle << "\n"<< "Program: Non-thesis Master's" << std::endl;
    }

    std::string getLevel() const override {
        return "Non-Thesis Masters Student";
    }
};

class DoctoralStudent : public GraduateStudent {
protected:
    std::string dissertationTitle;
    int yearsInProgram;

public:
    DoctoralStudent(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& dissertation, int years) : GraduateStudent(n, id, dept, adv), dissertationTitle(dissertation), yearsInProgram(years) {}

    void displayInfo() const override {
        GraduateStudent::displayInfo();
        std::cout << "Dissertation: " << dissertationTitle << "\n"<< "Years in Program: " << yearsInProgram << "\n"<< "Program: Doctoral Studies" << std::endl;
    }

    std::string getLevel() const override {
        return "Doctoral Student";
    }
};

class PhDCandidate : public DoctoralStudent {
public:
    PhDCandidate(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& dissertation, int years) : DoctoralStudent(n, id, dept, adv, dissertation, years) {}

    void displayInfo() const override {
        DoctoralStudent::displayInfo();
        std::cout << "Status: PhD Candidate (Advanced to Candidacy)" << std::endl;
    }

    std::string getLevel() const override {
        return "PhD Candidate";
    }
};

class PostDocFellow : public DoctoralStudent {
private:
    std::string researchGrant;

public:
    PostDocFellow(const std::string& n, const std::string& id, const std::string& dept, const std::string& adv, const std::string& grant): DoctoralStudent(n, id, dept, adv, "N/A", 0), researchGrant(grant) {}

    void displayInfo() const override {
        Student::displayInfo();
        std::cout << "Advisor: " << advisor << "\n"<< "Research Grant: " << researchGrant << "\n"<< "Dissertation: " << dissertationTitle << "\n"<< "Status: Post-Doctoral Fellow" << std::endl;
    }

    std::string getLevel() const override {
        return "Post-Doctoral Fellow";
    }
};

void printSeparator() {
    std::cout << std::string(60, '=') << std::endl;
}

int main() {
    std::cout << "---University Student Information System---" << std::endl;
    
    Freshman f("Amit", "UG101", "Computer Science", 1, 15);
    Sophomore so("Sarah", "UG201", "Mathematics", 2, 45);
    Junior j("Mike", "UG301", "Biology", 3, 75);
    Senior s("Emily", "UG401", "Chemistry", 4, 105);
    HonorsSenior hs("Neha", "UG401", "Physics", 4, 120, "Quantum Entanglement Thesis");
    ExchangeSenior es("Luca", "UG402", "Mechanical", 4, 110, "Politecnico di Milano");
    ThesisMastersStudent tm("Priya", "GR201", "Electrical", "Dr. Rao", "Smart Grid Optimization");
    NonThesisMastersStudent ntm("Raj", "GR202", "Civil", "Dr. Mehta", "Bridge Load Simulation");
    PhDCandidate phd("Sneha", "GR301", "Biotech", "Dr. Kapoor", "Gene Editing Ethics", 3);
    PostDocFellow pdf("Dr. Tanmay", "GR401", "AI Research", "Dr. Bose", "DARPA Grant");

    std::vector<Student*> students;
    students.push_back(&f);
    students.push_back(&so);
    students.push_back(&j);
    students.push_back(&s);
    students.push_back(&hs);
    students.push_back(&es);
    students.push_back(&tm);
    students.push_back(&ntm);
    students.push_back(&phd);
    students.push_back(&pdf);
    
    for (size_t i = 0; i < students.size(); ++i) {
        printSeparator();
        std::cout << "Student " << (i + 1) << ":\n";
        students[i]->displayInfo();
        std::cout << "\nAcademic Level: " << students[i]->getLevel() << std::endl;
        printSeparator();
        std::cout << std::endl;
    }

    std::cout << "\nDemonstrating Dynamic Binding:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "Student " << students[i]->getName()<< " is a: " << students[i]->getLevel() << std::endl;
    }

    std::cout << "\nType Identification using typeid:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "Type of " << students[i]->getName() << ": " << typeid(*students[i]).name() << std::endl;
    }

    //dynamic_cast for specific type handling
    for (size_t i = 0; i < students.size(); ++i) {
        if (auto honorsSenior = dynamic_cast<HonorsSenior*>(students[i])) {
            std::cout << "Special Recognition: " << students[i]->getName() <<" is an Honors Senior with outstanding research!" <<std::endl;
        }
        
        // Check for PhD Candidate
        if (auto phdCandidate = dynamic_cast<PhDCandidate*>(students[i])) {
            std::cout << "Research Milestone: " << students[i]->getName() <<" is a PhD Candidate advancing knowledge!" << std::endl;
        }
        
        // Check for Post-Doc Fellow
        if (auto postDoc = dynamic_cast<PostDocFellow*>(students[i])) {
            std::cout << "Advanced Research: " << students[i]->getName() << " is a Post-Doctoral Fellow with external funding!" << std::endl;
        }
    }

    //Display statistics
    std::cout << "\n--- Student Population Statistics ---" << std::endl;
    int undergradCount = 0, gradCount = 0, doctoralCount = 0;
    
    for (size_t i = 0; i < students.size(); ++i) {
        if (dynamic_cast<UndergraduateStudent*>(students[i])) {
            undergradCount++;
        } else if (dynamic_cast<MastersStudent*>(students[i])) {
            gradCount++;
        } else if (dynamic_cast<DoctoralStudent*>(students[i])) {
            doctoralCount++;
        }
    }
    
    std::cout << "Total Students: " << students.size() << std::endl;
    std::cout << "Undergraduate Students: " << undergradCount << std::endl;
    std::cout << "Master's Students: " << gradCount << std::endl;
    std::cout << "Doctoral Students & Fellows: " << doctoralCount << std::endl;

    return 0;
}