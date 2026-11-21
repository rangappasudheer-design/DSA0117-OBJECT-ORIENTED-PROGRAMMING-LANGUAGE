
#include <iostream>
#include <vector>
#include <chrono>
#include <memory>
using namespace std;
using namespace chrono;

// Base class
class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

// Outpatient bill
class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(double c, double t)
        : consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }
};

// Inpatient bill
class InPatient : public Bill {
    int days;
    double rate, surgery;

public:
    InPatient(int d, double r, double s)
        : days(d), rate(r), surgery(s) {}

    double total() const override {
        return days * rate + surgery;
    }
};

// Structure for switch approach
struct SimpleBill {
    int type;
    double a, b, c;
};

// Calculate using virtual functions
double virtualTotal(const vector<Bill*>& bills) {
    double sum = 0;

    for (const Bill* b : bills) {
        sum += b->total();
    }

    return sum;
}

// Calculate using switch
double switchTotal(const vector<SimpleBill>& bills) {
    double sum = 0;

    for (const auto& b : bills) {
        switch (b.type) {
            case 1:
                sum += b.a + b.b;
                break;

            case 2:
                sum += b.a * b.b + b.c;
                break;
        }
    }

    return sum;
}

volatile double result = 0;

// Measure virtual and switch performance
template <typename Function>
double measure(Function function) {
    auto start = steady_clock::now();

    result = function();

    auto end = steady_clock::now();

    return duration<double, milli>(end - start).count();
}

int main() {

    // B3.1: Ten bills
    vector<OutPatient> op;
    vector<InPatient> ip;
    vector<Bill*> virtualBills;
    vector<SimpleBill> simpleBills;

    op.reserve(5);
    ip.reserve(5);
    virtualBills.reserve(10);
    simpleBills.reserve(10);

    for (int i = 0; i < 10; i++) {

        if (i % 2 == 0) {
            op.emplace_back(500, 1200);
            virtualBills.push_back(&op.back());

            simpleBills.push_back({1, 500, 1200, 0});
        }
        else {
            ip.emplace_back(3, 2500, 40000);
            virtualBills.push_back(&ip.back());

            simpleBills.push_back({2, 3, 2500, 40000});
        }
    }

    cout << "B3.1 - Correctness\n";

    double v = virtualTotal(virtualBills);
    double s = switchTotal(simpleBills);

    cout << "Virtual Total: " << v << '\n';
    cout << "Switch Total: " << s << '\n';

    if (v == s)
        cout << "Both results are equal\n";

    // B3.2: Performance comparison
    cout << "\nB3.2 - Performance\n";

    for (int n : {1000, 1000000, 10000000}) {

        vector<OutPatient> outpatient;
        vector<InPatient> inpatient;
        vector<Bill*> vb;
        vector<SimpleBill> sb;

        outpatient.reserve((n + 1) / 2);
        inpatient.reserve(n / 2);
        vb.reserve(n);
        sb.reserve(n);

        for (int i = 0; i < n; i++) {

            if (i % 2 == 0) {
                outpatient.emplace_back(500, 1200);
                vb.push_back(&outpatient.back());

                sb.push_back({1, 500, 1200, 0});
            }
            else {
                inpatient.emplace_back(3, 2500, 40000);
                vb.push_back(&inpatient.back());

                sb.push_back({2, 3, 2500, 40000});
            }
        }

        double vt = measure([&]() {
            return virtualTotal(vb);
        });

        double st = measure([&]() {
            return switchTotal(sb);
        });

        cout << "\nBills: " << n << '\n';
        cout << "Virtual time: " << vt << " ms\n";
        cout << "Switch time: " << st << " ms\n";
    }

    return 0;
}
