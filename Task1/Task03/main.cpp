
#include <iostream>
using namespace std;

// Parcel class
class Parcel
{
public:
    double weight;
    bool express;
    bool insured;

    Parcel(double w, bool e = false, bool i = false)
        : weight(w), express(e), insured(i) {}
};

// Overloading for integer weight in grams
double charge(int grams)
{
    return grams * 0.05;
}

// Overloading for weight in kilograms
double charge(double kg, bool express = false,
              bool insured = false)
{
    double cost = kg * 50;

    if (express)
        cost += 30;

    if (insured)
        cost += 20;

    return cost;
}

// Overloading for Parcel object
double charge(const Parcel& p)
{
    return charge(p.weight, p.express, p.insured);
}

int main()
{
    cout << "Courier Charge Calculator\n\n";

    // Six function calls
    cout << "charge(500): "
         << charge(500) << endl;

    cout << "charge(2): "
         << charge(2) << endl;

    cout << "charge(2.0): "
         << charge(2.0) << endl;

    cout << "charge(2.0f): "
         << charge(2.0f) << endl;

    cout << "charge(2.0, true): "
         << charge(2.0, true) << endl;

    Parcel p(2.0, true, true);

    cout << "charge(Parcel): "
         << charge(p) << endl;

    return 0;
}
