
#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Bill {
protected:
    string patient;
    int billNumber;

public:
    Bill(string p, int b) {
        patient = p;
        billNumber = b;
    }

    // Pure virtual functions
    virtual double total() const = 0;
    virtual string type() const = 0;

    virtual void print() const {
        cout << type() << " | Bill No: " << billNumber
             << " | Patient: " << patient
             << " | Amount: " << total() << '\n';
    }

    // Virtual destructor
    virtual ~Bill() {}
};

// 1. Outpatient Bill
class OutPatientBill : public Bill {
private:
    double consultation, tests;

public:
    OutPatientBill(string p, int b, double c, double t)
        : Bill(p, b) {
        consultation = c;
        tests = t;
    }

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "Outpatient";
    }
};

// 2. Inpatient Bill
class InPatientBill : public Bill {
private:
    int days;
    double roomCharge, procedures, medicines;

public:
    InPatientBill(string p, int b, int d, double r,
                  double pr, double m)
        : Bill(p, b) {
        days = d;
        roomCharge = r;
        procedures = pr;
        medicines = m;
    }

    double total() const override {
        return days * roomCharge + procedures + medicines;
    }

    string type() const override {
        return "Inpatient";
    }
};

// 3. Day-care Bill
class DayCareBill : public Bill {
private:
    double packagePrice;

public:
    DayCareBill(string p, int b, double price)
        : Bill(p, b) {
        packagePrice = price;
    }

    double total() const override {
        return packagePrice;
    }

    string type() const override {
        return "Day-care";
    }
};

// 4. Emergency Bill
class EmergencyBill : public Bill {
private:
    double baseCharge, timeCharge;

public:
    EmergencyBill(string p, int b, double base, double time)
        : Bill(p, b) {
        baseCharge = base;
        timeCharge = time;
    }

    double total() const override {
        return baseCharge + timeCharge;
    }

    string type() const override {
        return "Emergency";
    }
};

// Main Function
int main() {

    // Array of base-class pointers
    Bill* bills[] = {
        new OutPatientBill("Ravi", 101, 500, 1200),
        new InPatientBill("Meena", 102, 3, 2500, 30000, 2500),
        new DayCareBill("Arun", 103, 15000),
        new EmergencyBill("Kumar", 104, 5000, 3000)
    };

    int n = 4;
    double dailyTotal = 0;

    cout << "HOSPITAL BILLING SYSTEM\n";
    cout << "-----------------------\n";

    // Runtime polymorphism
    for (int i = 0; i < n; i++) {
        bills[i]->print();
        dailyTotal += bills[i]->total();
    }

    cout << "-----------------------\n";
    cout << "Daily Total: " << dailyTotal << '\n';

    // Release memory
    for (int i = 0; i < n; i++) {
        delete bills[i];
    }

    return 0;
}
