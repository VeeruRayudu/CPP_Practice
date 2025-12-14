#include "4887766_MD2_Task5_AutomotiveSubsystem.h"
#include "4887766_MD2_Task5_MotorController.h"
#include "4887766_MD2_Task5_BrakeController.h"

int main()
{
    TelemetryProvider tp1("SRC_BAS_Unit1");
    TelemetryProvider tp2("SRC_EXT_Unit2");

    AutomotiveSubsystem sub;

    // test case: tp1 only
    sub.addTelemetry(&tp1);
    sub.addController(std::make_unique<MotorController>("M1", 7000)); // delegated constructor (Basic)

    auto r1 = sub.runAll();
    for (auto &s : r1)
        std::cout << s << "\n";

    // add another controller and provider for more tests
    sub.addController(std::make_unique<BrakeController>("B1", 1200.0, TelemetryLevel::EXTENDED));
    sub.addTelemetry(&tp2);

    auto r2 = sub.runAll();
    std::cout << "--- second run ---\n";
    for (auto &s : r2)
        std::cout << s << "\n";

    // third test: empty subsystem (new)
    AutomotiveSubsystem sub2;
    sub2.addController(std::make_unique<MotorController>("M1", 7000));
    sub2.addController(std::make_unique<BrakeController>("B1", 1200.0, TelemetryLevel::EXTENDED));
    auto r3 = sub2.runAll();
    std::cout << "--- third run (no providers) ---\n";
    for (auto &s : r3)
        std::cout << s << "\n";

    return 0;
}