#include "SignalBuffer.h"
#include <array>

int main() {
    std::array<SignalBuffer, 5> buffer = {
        SignalBuffer{501, "Alpha", -65.0f, 1620000000, Status::VALID},
        SignalBuffer{502, "Beta", -85.0f, 1620000100, Status::WEAK},
        SignalBuffer{503, "Gamma", -120.0f, 1620000200, Status::LOST},
        SignalBuffer{504, "Delta", -70.0f, 1620000300, Status::VALID},
        SignalBuffer{505, "Epsilon", -95.0f, 1620000400, Status::WEAK}
    };

    SignalBuffer sb1;
    SignalBuffer sb2(502, "Beta", -85.0f, 1620000100, Status::WEAK);
    SignalBuffer sb3{503, "Gamma", -120.0f, 1620000200, Status::LOST};
    SignalBuffer sb4{};

    std::cout << "\n-----------------INITIAL DETAILS-----------------\n";
    std::cout << "Default:\n"; sb1.print();
    std::cout << "\nMember-list:\n"; sb2.print();
    std::cout << "\nUniform initialization:\n"; sb3.print();
    std::cout << "\nValue initialization:\n"; sb4.print();

    sb1.updateStrength(-65.0f);
    sb4.setStatus(Status::VALID);

    std::cout << "\n-----------------AFTER UPDATE-----------------\n";
    sb1.print();
    sb4.print();

    std::cout << "\n-----------------LOGGER-----------------\n";
    logByRef(sb2);
    logByRRef(std::move(sb3));
    logByPtr(&buffer[4]);

    float threshold = -90.0f;
    auto lambda1 = [threshold]() { return threshold; };
    auto lambda2 = [&threshold]() { return threshold; };
    auto lambda3 = [=]() { return threshold; };
    auto lambda4 = [&]() { return threshold + 5.0f; };
    auto lambda5 = [limit = threshold + 5.0f]() { return limit; };
    auto lambda6 = [threshold]() mutable { threshold -= 0.1f; return threshold; };

    std::cout << "\n-----------------LAMBDA FUNCTIONS-----------------";
    std::cout << "\ncapture by value: " << lambda1();
    std::cout << "\ncapture by reference: " << lambda2();
    std::cout << "\ncapture all by value: " << lambda3();
    std::cout << "\ncapture all by reference: " << lambda4();
    std::cout << "\ninit capture: " << lambda5();
    std::cout << "\nmutable lambda: " << lambda6() << "\n";

    auto filter = [](const SignalBuffer& b) {
        return b.getStrength() < -90.0f || b.getStatus() == Status::LOST;
    };

    std::array<SignalBuffer, 5> weakSignals{};
    int count = 0;
    for (auto& b : buffer) {
        if (filter(b)) {
            weakSignals[count++] = std::move(b);
        }
    }

    std::cout << "\n-----------------WEAK SIGNALS-----------------\n";
    for (int i = 0; i < count; ++i) {
        weakSignals[i].print();
    }

    return 0;
}