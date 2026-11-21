
#include <iostream>
#include <string>
using namespace std;

// Base abstract class
class Bill {
protected:
    string patient;

public:
    Bill(const string& p) : patient(p) {}

    virtual ~Bill() = default;

    // Pure virtual function
    virtual double total() const = 0;

    // Virtual function
    virtual string type() const {
        return "Bill";
    }

    void print() const {
        cout << type() << " " << patient
             << ": " << total() << '\n';
    }
};

// Derived class 1
class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(const string& p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OP";
    }
};

// Derived class 2
class InPatient : public Bill {
    int days;
    double perDay, surgery;

public:
    InPatient(const string& p, int d, double rate, double s)
        : Bill(p), days(d), perDay(rate), surgery(s) {}

    double total() const override {
        return days * perDay + surgery;
    }

    string type() const override {
        return "IP";
    }
};

int main() {

    // Base class pointers
    Bill* bills[] = {
        new OutPatient("Ravi", 500, 1200),
        new InPatient("Meena", 3, 2500, 40000)
    };

    double sum = 0;

    // Runtime polymorphism
    for (Bill* b : bills) {
        b->print();
        sum += b->total();
    }

    cout << "Total " << sum << '\n';

    // Release memory
    for (Bill* b : bills) {
        delete b;
    }

    return 0;
}
