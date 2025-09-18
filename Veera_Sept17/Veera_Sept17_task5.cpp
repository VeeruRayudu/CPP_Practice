#include <iostream>
#include <string>

class ParcelAnalyzer
{
public:
    std::string classifyWeight(int grams)
    {
        if (grams < 500)
            return "Light";
        else if (grams <= 2000)
            return "Medium";
        else
            return "Heavy";
    }

    std::string classifyWeight(float kilograms)
    {
        if (kilograms < 0.5f)
            return "Light";
        else if (kilograms <= 2.0f)
            return "Medium";
        else
            return "Heavy";
    }

    std::string classifyWeight(double pounds)
    {
        if (pounds < 1.1)
            return "Light";
        else if (pounds <= 4.4)
            return "Medium";
        else
            return "Heavy";
    }
};

void printClassification(const std::string& label)
{
    std::cout << "Classification: " << label << std::endl;
}

int main()
{
    ParcelAnalyzer analyzer;

    std::cout << "450 grams -> ";
    printClassification(analyzer.classifyWeight(450));

    std::cout << "1500 grams -> ";
    printClassification(analyzer.classifyWeight(1500));

    std::cout << "2500 grams -> ";
    printClassification(analyzer.classifyWeight(2500));

    std::cout << "0.3 kg -> ";
    printClassification(analyzer.classifyWeight(0.3f));

    std::cout << "1.5 kg -> ";
    printClassification(analyzer.classifyWeight(1.5f));

    std::cout << "3.0 kg -> ";
    printClassification(analyzer.classifyWeight(3.0f));

    std::cout << "0.9 lb -> ";
    printClassification(analyzer.classifyWeight(0.9));

    std::cout << "2.5 lb -> ";
    printClassification(analyzer.classifyWeight(2.5));

    std::cout << "5.0 lb -> ";
    printClassification(analyzer.classifyWeight(5.0));

    return 0;
}
