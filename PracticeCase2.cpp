#include <iostream>
#include <string>
using namespace std;

// ========================================
// BASE CLASS "Vehicle"
// ========================================
class Vehicle {
protected:
    string brand;
    int year;

public:
    // Constructor
    Vehicle(string b, int y) {
        brand = b;
        year = y;
        cout << "Vehicle created: " << brand << " (" << year << ")" << endl;
    }

    // Destructor
    virtual ~Vehicle() {
        cout << "Vehicle destroyed: " << brand << endl;
    }

    // Virtual method to show info
    virtual void showInfo() {
        cout << "Vehicle: " << brand << ", " << year << " year" << endl;
    }

    // Virtual method "move"
    virtual void move() {
        cout << brand << " starts moving" << endl;
    }
};

// ========================================
// DERIVED CLASS "Car" (inherits Vehicle)
// ========================================
class Car : public Vehicle {
private:
    int doors;

public:
    // Constructor
    Car(string b, int y, int d) : Vehicle(b, y) {
        doors = d;
        cout << "  -> Car info added: " << doors << " doors" << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car destroyed: " << brand << endl;
    }

    // Override showInfo
    void showInfo() override {
        cout << "Car: " << brand << ", " << year << " year, " << doors << " doors" << endl;
    }

    // Override move
    void move() override {
        cout << brand << " drives on 4 wheels" << endl;
    }

    // New method (not in base class)
    void honk() {
        cout << brand << " honks: BEEP-BEEP!" << endl;
    }
};

// ========================================
// TEST PROGRAM
// ========================================
int main() {
    cout << "========== CLASS TESTING ==========\n" << endl;

    // 1. Create objects
    cout << "--- CREATING OBJECTS ---" << endl;
    Car car1("Toyota", 2020, 4);
    Car car2("BMW", 2022, 2);
    cout << endl;

    // 2. Call methods
    cout << "--- CALLING METHODS ---" << endl;

    car1.showInfo();
    car1.move();
    car1.honk();
    cout << endl;

    car2.showInfo();
    car2.move();

    cout << "\n========== END OF TEST ==========" << endl;
    cout << "Press Enter to exit...";
    cin.get();
    return 0;
}