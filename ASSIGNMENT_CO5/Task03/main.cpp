
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Bill class
class Bill {
private:
    double amount;
    string packageName;

public:
    Bill(double a, string p) {
        amount = a;
        packageName = p;
    }

    double getAmount() const {
        return amount;
    }

    string getPackageName() const {
        return packageName;
    }
};

// Abstract base class
class Payer {
public:
    virtual double amountCovered(const Bill& bill) const = 0;

    virtual ~Payer() {}
};

// SelfPay class
class SelfPay : public Payer {
public:
    double amountCovered(const Bill& bill) const override {
        return bill.getAmount();
    }
};

// Insurance class
class Insurance : public Payer {
private:
    double coverLimit;
    double coPaymentPercent;

public:
    Insurance(double limit, double copay) {
        coverLimit = limit;
        coPaymentPercent = copay;
    }

    double amountCovered(const Bill& bill) const override {
        double eligibleAmount =
            min(bill.getAmount(), coverLimit);

        double insuranceAmount =
            eligibleAmount * (100 - coPaymentPercent) / 100;

        return insuranceAmount;
    }
};

// GovernmentScheme class
class GovernmentScheme : public Payer {
private:
    double packageRate;

public:
    GovernmentScheme(double rate) {
        packageRate = rate;
    }

    double amountCovered(const Bill& bill) const override {
        return min(bill.getAmount(), packageRate);
    }
};

// Main function
int main() {

    Bill hospitalBill(10000, "General");

    SelfPay self;
    Insurance insurance(8000, 20);
    GovernmentScheme government(7000);

    // Base class pointers
    Payer* payers[3];

    payers[0] = &self;
    payers[1] = &insurance;
    payers[2] = &government;

    string names[3] = {
        "Self Pay",
        "Insurance",
        "Government Scheme"
    };

    cout << "HOSPITAL PAYMENT SYSTEM\n";
    cout << "-----------------------\n";

    for (int i = 0; i < 3; i++) {
        cout << names[i] << " covers: Rs. "
             << payers[i]->amountCovered(hospitalBill)
             << endl;
    }

    return 0;
}
