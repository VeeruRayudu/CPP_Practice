#include <iostream>
#include <cmath>
#include <iomanip>

class Quadrilateral {
protected:
    float *sides;
    float *angles;

public:
    //Constructor
    Quadrilateral(const float s[4], const float a[4]) {
        sides = new float[4];
        angles = new float[4];
        
        for (int i = 0; i < 4; i++) {
            sides[i] = s[i];
            angles[i] = a[i];
        }
    }

    //Copy constructor
    Quadrilateral(const Quadrilateral& other) {
        sides = new float[4];
        angles = new float[4];
        
        for (int i = 0; i < 4; i++) {
            sides[i] = other.sides[i];
            angles[i] = other.angles[i];
        }
    }

    Quadrilateral& operator=(const Quadrilateral& other) {
        if (this != &other) {
            delete[] sides;
            delete[] angles;
            
            sides = new float[4];
            angles = new float[4];
            
            for (int i = 0; i < 4; i++) {
                sides[i] = other.sides[i];
                angles[i] = other.angles[i];
            }
        }
        return *this;
    }

    virtual ~Quadrilateral() {
        delete[] sides;
        delete[] angles;
        std::cout << "Quadrilateral destructor called" << std::endl;
    }

    virtual bool isValid() const {
        float sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += angles[i];
        }
        return std::fabs(sum - 360.0f) < 0.001f;
    }

    virtual float area() const {
        return 0.0f; 
    }

    float operator()() const {
        float perimeter = 0;
        for (int i = 0; i < 4; i++) {
            perimeter += sides[i];
        }
        return perimeter;
    }

    operator float() const {
        return area();
    }

    const float* getSides() const { return sides; }
    const float* getAngles() const { return angles; }

    friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& q);
};

std::ostream& operator<<(std::ostream& os, const Quadrilateral& q) {
    os << "Quadrilateral - Sides: [";
    for (int i = 0; i < 4; i++) {
        os << q.sides[i];
        if (i < 3) os << ", ";
    }
    os << "], Angles: [";
    for (int i = 0; i < 4; i++) {
        os << q.angles[i];
        if (i < 3) os << ", ";
    }
    os << "]";
    return os;
}

//Trapezoid class
class Trapezoid : public Quadrilateral {
public:
    Trapezoid(const float s[4], const float a[4]) : Quadrilateral(s, a) {}

    bool isValid() const override {
        if (!Quadrilateral::isValid()) return false;
        for (int i = 0; i < 4; i++) {
            if (std::fabs(angles[i] + angles[(i + 1) % 4] - 180.0f) < 0.001f) {
                return true;
            }
        }
        return false;
    }

    float area() const override {
        float a = sides[0];
        float b = sides[2];
        float height = sides[1] * std::sin(angles[1] * M_PI / 180.0f);
        return 0.5f * (a + b) * height;
    }

    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& t);
};

std::ostream& operator<<(std::ostream& os, const Trapezoid& t) {
    os << "Trapezoid - Sides: [";
    for (int i = 0; i < 4; i++) {
        os << t.getSides()[i];
        if (i < 3) os << ", ";
    }
    os << "], Angles: [";
    for (int i = 0; i < 4; i++) {
        os << t.getAngles()[i];
        if (i < 3) os << ", ";
    }
    os << "]";
    return os;
}

// Parallelogram class
class Parallelogram : public Trapezoid {
public:
    Parallelogram(const float s[4], const float a[4]) : Trapezoid(s, a) {}

    bool isValid() const override {
        if (!Trapezoid::isValid()) return false;
        bool sidesEqual = (std::fabs(sides[0] - sides[2]) < 0.001f) && (std::fabs(sides[1] - sides[3]) < 0.001f);
        bool anglesEqual = (std::fabs(angles[0] - angles[2]) < 0.001f) && (std::fabs(angles[1] - angles[3]) < 0.001f);
        
        return sidesEqual && anglesEqual;
    }

    float area() const override {
        float base = sides[0];
        float height = sides[1] * std::sin(angles[1] * M_PI / 180.0f);
        return base * height;
    }

    friend std::ostream& operator<<(std::ostream& os, const Parallelogram& p);
};

std::ostream& operator<<(std::ostream& os, const Parallelogram& p) {
    os << "Parallelogram - Sides: [";
    for (int i = 0; i < 4; i++) {
        os << p.getSides()[i];
        if (i < 3) os << ", ";
    }
    os << "], Angles: [";
    for (int i = 0; i < 4; i++) {
        os << p.getAngles()[i];
        if (i < 3) os << ", ";
    }
    os << "]";
    return os;
}

// Rectangle class
class Rectangle : public Parallelogram {
public:
    Rectangle(const float s[4], const float a[4]) : Parallelogram(s, a) {}

    bool isValid() const override {
        if (!Parallelogram::isValid()) return false;
        
        for (int i = 0; i < 4; i++) {
            if (std::fabs(angles[i] - 90.0f) > 0.001f) {
                return false;
            }
        }
        return true;
    }

    float area() const override {
        return sides[0] * sides[1];
    }

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);
};

std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    os << "Rectangle - Sides: [";
    for (int i = 0; i < 4; i++) {
        os << r.getSides()[i];
        if (i < 3) os << ", ";
    }
    os << "], Angles: [";
    for (int i = 0; i < 4; i++) {
        os << r.getAngles()[i];
        if (i < 3) os << ", ";
    }
    os << "]";
    return os;
}

// Square class
class Square : public Rectangle {
public:
    Square(const float s[4], const float a[4]) : Rectangle(s, a) {}

    bool isValid() const override {
        if (!Rectangle::isValid()) return false;

        for (int i = 1; i < 4; i++) {
            if (std::fabs(sides[i] - sides[0]) > 0.001f) {
                return false;
            }
        }
        return true;
    }

    float area() const override {
        return sides[0] * sides[0];
    }

    friend std::ostream& operator<<(std::ostream& os, const Square& s);
};

std::ostream& operator<<(std::ostream& os, const Square& s) {
    os << "Square - Sides: [";
    for (int i = 0; i < 4; i++) {
        os << s.getSides()[i];
        if (i < 3) os << ", ";
    }
    os << "], Angles: [";
    for (int i = 0; i < 4; i++) {
        os << s.getAngles()[i];
        if (i < 3) os << ", ";
    }
    os << "]";
    return os;
}

//Global operator == to compare areas
bool operator==(const Quadrilateral& q1, const Quadrilateral& q2) {
    return std::fabs(q1.area() - q2.area()) < 0.001f;
}

int main() {
    std::cout << "=== Geometry Toolkit for Shape Classification ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    float squareSides[] = {5, 5, 5, 5};
    float squareAngles[] = {90, 90, 90, 90};
    Square sq(squareSides, squareAngles);

    float rectSides[] = {6, 4, 6, 4};
    float rectAngles[] = {90, 90, 90, 90};
    Rectangle rect(rectSides, rectAngles);

    float paraSides[] = {6, 4, 6, 4};
    float paraAngles[] = {110, 70, 110, 70};
    Parallelogram para(paraSides, paraAngles);

    float trapSides[] = {6, 5, 4, 3};
    float trapAngles[] = {100, 80, 100, 80};
    Trapezoid trap(trapSides, trapAngles);

    float quadSides[] = {3, 4, 5, 6};
    float quadAngles[] = {90, 90, 90, 90};
    Quadrilateral quad(quadSides, quadAngles);

    Quadrilateral* shapes[] = {&quad, &trap, &para, &rect, &sq};
    const char* shapeNames[] = {"Quadrilateral", "Trapezoid", "Parallelogram", "Rectangle", "Square"};

    for (int i = 0; i < 5; i++) {
        std::cout << "\n" << shapeNames[i] << ":" << std::endl;
        std::cout << *shapes[i] << std::endl;
        std::cout << "Is Valid: " << (shapes[i]->isValid() ? "Yes" : "No") << std::endl;
        std::cout << "Area: " << shapes[i]->area() << " square units" << std::endl;
        std::cout << "Perimeter: " << (*shapes[i])() << " units" << std::endl;
    }

    std::cout << "Rectangle area: " << rect.area() << std::endl;
    std::cout << "Square area: " << sq.area() << std::endl;
    if (rect == sq) {
        std::cout << "Rectangle and Square have equal areas" << std::endl;
    } else {
        std::cout << "Rectangle and Square have different areas" << std::endl;
    }

    std::cout << "\nRectangle area: " << rect.area() << std::endl;
    std::cout << "Parallelogram area: " << para.area() << std::endl;
    if (rect == para) {
        std::cout << "Rectangle and Parallelogram have equal areas" << std::endl;
    } else {
        std::cout << "Rectangle and Parallelogram have different areas" << std::endl;
    }

    float squareArea = float(sq);
    float rectangleArea = float(rect);
    std::cout << "Square area via float(): " << squareArea << std::endl;
    std::cout << "Rectangle area via float(): " << rectangleArea << std::endl;

    std::cout << "Square perimeter: " << sq() << " units" << std::endl;
    std::cout << "Rectangle perimeter: " << rect() << " units" << std::endl;
    std::cout << "Parallelogram perimeter: " << para() << " units" << std::endl;
    std::cout << "Trapezoid perimeter: " << trap() << " units" << std::endl;
    std::cout << "Quadrilateral perimeter: " << quad() << " units" << std::endl;

    Square sqCopy = sq; // Copy constructor
    std::cout << "Original Square area: " << sq.area() << std::endl;
    std::cout << "Copied Square area: " << sqCopy.area() <<std::endl;
    
    Rectangle rectAssigned(rectSides, rectAngles);
    rectAssigned = rect; // Assignment operator
    std::cout << "Assigned Rectangle area: " << rectAssigned.area()<< std::endl;

    return 0;
}