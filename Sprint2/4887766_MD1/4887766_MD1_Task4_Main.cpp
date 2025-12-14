#include "4887766_MD1_Task4_SafetyFeature.h"

int main()
{
    Airbag airbag("Front Airbag", true, 30);
    ABS abs("Anti_lock Braking", true, 98.5);

    airbag.activate();
    abs.activate();

    // SafetyFeature sf(airbag); ---> Compile-time error: cannot be referenced -- it is a deleted function

    return 0;
}