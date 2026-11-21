
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

// Abstract Bill class
class Bill {
protected:
    string patient;

public:
    Bill(string p) : patient(p) {}

    virtual double total() const = 0;
    virtual string type() const = 0;

    string getPatient() const {
        return patient;
    }

    virtual ~Bill() = default;
};

// Existing bill type 1
class OutPatient : public Bill {
private:
    double consultation;
    double tests;

public:
    OutPatient(string p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "Outpatient";
    }
};

// Existing bill type 2
class InPatient : public Bill {
private:
    int days;
    double perDay;
    double surgery;

public:
    InPatient(string p, int d, double rate, double s)
        : Bill(p), days(d), perDay(rate), surgery(s) {}

    double total() const override {
        return days * perDay + surgery;
    }

    string type() const override {
        return "Inpatient";
    }
};

// NEW bill type
class EmergencyBill : public Bill {
private:
    double emergencyCharge;
    double treatmentCharge;

public:
    EmergencyBill(string p, double e, double t)
        : Bill(p), emergencyCharge(e), treatmentCharge(t) {}

    double total() const override {
        return emergencyCharge + treatmentCharge;
    }

    string type() const override {
        return "Emergency";
    }
};

// Abstract Payer class
class Payer {
public:
    virtual double amountCovered(const Bill& bill) const = 0;

    virtual string payerName() const = 0;

    virtual ~Payer() = default;
};

// Existing payer type
class SelfPay : public Payer {
public:
    double amountCovered(const Bill& bill) const override {
        return bill.total();
    }

    string payerName() const override {
        return "Self Pay";
    }
};

// NEW payer type
class CorporatePayer : public Payer {
private:
    double coveragePercent;
    double maximumLimit;

public:
    CorporatePayer(double percent, double limit)
        : coveragePercent(percent), maximumLimit(limit) {}

    double amountCovered(const Bill& bill) const override {
        double eligible = bill.total() * coveragePercent / 100;
        return min(eligible, maximumLimit);
    }

    string payerName() const override {
        return "Corporate";
    }
};

int main() {

    // Store different bill objects safely
    vector<unique_ptr<Bill>> bills;

    bills.push_back(
        make_unique<OutPatient>("Ravi", 500, 1200)
    );

    bills.push_back(
        make_unique<InPatient>("Meena", 3, 2500, 40000)
    );

    // Add the new emergency bill
    bills.push_back(
        make_unique<EmergencyBill>("Kumar", 3000, 5000)
    );

    SelfPay self;
    CorporatePayer corporate(70, 30000);

    // Base-class pointers to different payer objects
    Payer* payers[] = { &self, &corporate };

    cout << "HOSPITAL BILLING SYSTEM\n";
    cout << "-----------------------\n";

    for (const auto& bill : bills) {

        cout << "\nBill Type: " << bill->type();
        cout << "\nPatient: " << bill->getPatient();
        cout << "\nTotal Bill: Rs. " << bill->total();

        for (Payer* payer : payers) {
            cout << "\n" << payer->payerName()
                 << " Covers: Rs. "
                 << payer->amountCovered(*bill);
        }

        cout << "\n";
    }

    cout << "\nProgram completed successfully.\n";

    return 0;
}
