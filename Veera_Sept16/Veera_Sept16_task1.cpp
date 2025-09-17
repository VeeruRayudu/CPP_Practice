#include <iostream>
#include <string>

class LaneBoundary
{
private:
    float curvature;
    int laneIdentifier;

public:
    LaneBoundary(float _curvature, int _laneIdentifier) : curvature(_curvature), laneIdentifier(_laneIdentifier) {}

    // Getters
    float getCurvature() const
    {
        return curvature;
    }
    int getLaneIdentifier() const
    {
        return laneIdentifier;
    }

    bool compareCurvature(const LaneBoundary &other) const
    {
        return this->curvature > other.getCurvature();
    }

    void displaly() const
    {
        std::cout << "\n---------Lane Details---------------";
        std::cout << "\nLane ID: " << laneIdentifier;
        std::cout << "\nCurvature: " << curvature << std::endl;
    }
};

bool isCurvatureGreater(const LaneBoundary &lane1, const LaneBoundary &lane2)
{
    return lane1.getCurvature() > lane2.getCurvature();
}

void printLaneComparision(const LaneBoundary &lane1, const LaneBoundary &lane2)
{
    if (isCurvatureGreater(lane1, lane2))
    {
        std::cout << "Lane ID " << lane1.getLaneIdentifier() << " has greater curvature " << lane1.getCurvature() << std::endl;
    }
    else
    {
        std::cout << "Lane ID " << lane2.getLaneIdentifier() << " has greater curvature " << lane2.getCurvature() << std::endl;
    }
}

int main()
{
    LaneBoundary lane1(0.015, 1);
    LaneBoundary lane2(0.023, 2);

    lane1.displaly();
    lane2.displaly();
    std::cout << "\n-----Lane Comparision using Member functions---------";

    if (lane1.compareCurvature(lane2))
    {
        std::cout << "\nLane ID " << lane1.getLaneIdentifier() << " has greater curvature " << lane1.getCurvature() << std::endl;
    }
    else if (lane2.compareCurvature(lane1))
    {
        std::cout << "\nLane ID " << lane2.getLaneIdentifier() << " has greater curvature " << lane2.getCurvature() << std::endl;
    }
    else
    {
        std::cout << "\nLane ID " << lane1.getLaneIdentifier() << " curvature is equal to Lane ID " << lane2.getCurvature() << " curvature" << std::endl;
    }

    std::cout << "\n------Lane Comparision using Global functions--------\n";
    printLaneComparision(lane1, lane2);

    return 0;
}
