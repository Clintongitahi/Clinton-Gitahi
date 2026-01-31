#include <iostream>

class Square {
protected:
    double side;

public:
    Square(double s) : side(s) {
        std::cout << "Square Constructor: Side set to " << side << std::endl;
    }

    virtual ~Square() {
        std::cout << "Square Destructor called." << std::endl;
    }

    double getPeri() const {
        return 4 * side;
    }

    double getArea() const {
        return side * side;
    }
};

class Cube : public Square {
public:
    Cube(double s) : Square(s) {
        std::cout << "Cube Constructor called." << std::endl;
    }

    ~Cube() {
        std::cout << "Cube Destructor called." << std::endl;
    }

    double getArea() const {
        return 6 * (side * side);
    }

    double getVolume() const {
        return side * side * side;
    }
};

int main() {
    std::cout << "--- Square Object ---" << std::endl;
    Square mySquare(5.0);
    std::cout << "Perimeter: " << mySquare.getPeri() << std::endl;
    std::cout << "Area: " << mySquare.getArea() << std::endl;

    std::cout << "\n--- Cube Object ---" << std::endl;
    Cube myCube(3.0);
    std::cout << "Surface Area: " << myCube.getArea() << std::endl;
    std::cout << "Volume: " << myCube.getVolume() << std::endl;
    std::cout << "--------------------" << std::endl;

    return 0;
}