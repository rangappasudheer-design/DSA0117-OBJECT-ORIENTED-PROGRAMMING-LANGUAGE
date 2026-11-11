
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Zone declaration
enum class Zone
{
    Inner,
    Middle,
    Outer
};

// Passenger class
class Passenger
{
private:
    string name;
    string category;

public:
    Passenger(string n, string c)
    {
        name = n;
        category = c;
    }

    void displayPassenger()
    {
        cout << "Passenger: " << name << endl;
        cout << "Category: " << category << endl;
    }
};

// FareTable class
class FareTable
{
public:
    static long long getFare(Zone z)
    {
        switch (z)
        {
            case Zone::Inner:
                return 1000;

            case Zone::Middle:
                return 2000;

            case Zone::Outer:
                return 3000;
        }

        return 0;
    }
};

// Journey class
class Journey
{
private:
    Zone zone;
    bool peak;

public:
    Journey(Zone z, bool p)
    {
        zone = z;
        peak = p;
    }

    long long calculateFare()
    {
        long long amount = FareTable::getFare(zone);

        if (peak)
        {
            amount = amount + (amount * 20 / 100);
        }

        return amount;
    }
};

// SmartCard class
class SmartCard
{
private:
    long long balance;
    const long long MIN_BALANCE = 5000;

public:
    SmartCard(long long b)
    {
        balance = b;
    }

    bool canTravel(long long fare)
    {
        return balance >= fare &&
               balance - fare >= MIN_BALANCE;
    }

    void deduct(long long fare)
    {
        if (canTravel(fare))
        {
            balance -= fare;
            cout << "Journey Successful" << endl;
        }
        else
        {
            cout << "Journey Denied: Low Balance" << endl;
        }
    }

    void displayBalance()
    {
        cout << "Remaining Balance: Rs "
             << balance / 100 << "."
             << setw(2) << setfill('0')
             << balance % 100 << endl;
    }
};

// Main function
int main()
{
    Passenger p1("Sudheer", "Student");

    SmartCard card(10000);

    p1.displayPassenger();

    cout << "\nInitial Smart Card Balance: Rs 100.00\n";

    Journey j1(Zone::Inner, false);

    long long fare1 = j1.calculateFare();

    cout << "\nJourney 1 Fare: Rs "
         << fare1 / 100 << "."
         << setw(2) << setfill('0')
         << fare1 % 100 << endl;

    card.deduct(fare1);
    card.displayBalance();

    Journey j2(Zone::Outer, true);

    long long fare2 = j2.calculateFare();

    cout << "\nJourney 2 Fare: Rs "
         << fare2 / 100 << "."
         << setw(2) << setfill('0')
         << fare2 % 100 << endl;

    card.deduct(fare2);
    card.displayBalance();

    Journey j3(Zone::Middle, false);

    long long fare3 = j3.calculateFare();

    cout << "\nJourney 3 Fare: Rs "
         << fare3 / 100 << "."
         << setw(2) << setfill('0')
         << fare3 % 100 << endl;

    card.deduct(fare3);
    card.displayBalance();

    return 0;
}
