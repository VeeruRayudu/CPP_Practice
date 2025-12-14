#include "TelemetryPacket.h"

int main() {
    TelemetryPacket packets[5];
    TelemetryPacket p1(201, "TEMP", 1620000000ULL);
    TelemetryPacket p2{202, "PRESS", 1620000100ULL};
    TelemetryPacket p3 = TelemetryPacket();
    TelemetryPacket temp(204, "GPS", 1620000400ULL);

    packets[0] = TelemetryPacket();
    packets[1] = std::move(p1);
    packets[2] = std::move(p2);
    packets[3] = std::move(p3);
    packets[4] = std::move(temp);

    packets[0].setReadings(75.0, 101.3);
    packets[1].setReadings(95.2, 100.8);
    packets[2].setReadings(60.5, 110.0);
    packets[3].setReadings(120.3, 95.0);
    packets[4].setReadings(20.0, 101.0);

    packets[0].setLevel(Level::OK);
    packets[1].setLevel(Level::WARN);
    packets[2].setLevel(Level::OK);
    packets[3].setLevel(Level::CRITICAL);
    packets[4].setLevel(Level::OK);

    logByRef(packets[1]);
    logByRRef(std::move(packets[2]));
    std::cout << "After move:\n";
    packets[2].print();

    std::cout << "\nMove constructor:\n";
    TelemetryPacket moved = std::move(packets[1]);
    std::cout << "\nMoved new object:\n";
    moved.print();
    std::cout << "\nMoved-from object:\n";
    packets[1].print();

    std::cout << "\nMove assignment:\n";
    packets[4] = std::move(moved);
    std::cout << "\nMoved new object:\n";
    packets[4].print();
    std::cout << "\nMoved-from object:\n";
    moved.print();

    float threshold = 100.0f;
    auto byValue = [threshold]() { return threshold; };
    auto byRef = [&threshold]() { return threshold; };
    auto allByValue = [=]() { return threshold; };
    auto allByRef = [&]() { return threshold; };
    auto initCap = [limit = threshold * 1.1f]() { return limit; };
    auto mutLam = [threshold]() mutable { threshold += 1; return threshold; };

    std::cout << "Before threshold change: " << threshold << '\n';
    std::cout << "byValue: " << byValue() << '\n';

    threshold = 60.0;
    std::cout << "\nAfter threshold change: " << threshold << '\n';
    std::cout << "byRef: " << byRef() << '\n';

    std::cout << "\ninit-capture with limit=110:\n";
    std::cout << "initCap: " << initCap() << '\n';

    std::cout << "\nMutable lambda returns: " << mutLam() << ", outer threshold: " << threshold << '\n';

    auto isCritical = [](const TelemetryPacket& p) {
        return p.getTemperature() > 100.0 || p.getLevel() == Level::CRITICAL;
    };

    TelemetryPacket filtered[5];
    size_t count = filterCritical(packets, 5, filtered, 5, isCritical);

    std::cout << "\nFiltered critical packets:\n";
    for (size_t i = 0; i < count; ++i) {
        filtered[i].print();
    }

    return 0;
}