#include "4887766_MD1_Task4_SafetyFeature.h"
#include <iostream>

int main() {
    Airbag airbag("Front Airbag", true, 30);
    ABS abs("Anti-lock Braking", true, 98.5);

    std::cout << "\nActivating Safety Features:\n";

    // Polymorphic behavior via base class references
    SafetyFeature& sf1 = airbag;
    SafetyFeature& sf2 = abs;

    sf1.activate();
    sf2.activate();

    std::cout << std::endl;
    return 0;
}