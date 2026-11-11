
#include <iostream>

using namespace std;

const long long MIN_BALANCE = 5000;

// Procedural Programming
bool canTravel(long long balance, long long fare)
{
    return fare > 0 &&
           balance >= fare &&
           balance - fare >= MIN_BALANCE;
}

void deductFare(long long &balance, long long fare)
{
    if (canTravel(balance, fare))
    {
        balance -= fare;
        cout << "Fare Rs " << fare / 100
             << ".00 deducted successfully\n";
    }
    else
    {
        cout << "Journey Denied (Low Balance)\n";
    }
}

// Object-Oriented Programming
class SmartCard
{
private:
    long long balance;

public:
    SmartCard(long long b)
    {
        balance = b;
    }

    bool canTravel(long long fare) const
    {
        return fare > 0 &&
               balance >= fare &&
               balance - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare)
    {
        if (canTravel(fare))
        {
            balance -= fare;
            return true;
        }

        return false;
    }

    long long getBalance() const
    {
        return balance;
    }
};

int main()
{
    long long fares[] = {1000, 3600, 2000};

    // Procedural Version
    cout << "PROCEDURAL PROGRAMMING\n";

    long long balance = 10000;

    for (long long fare : fares)
    {
        deductFare(balance, fare);
        cout << "Balance Rs " << balance / 100
             << ".00\n";
    }

    // Object-Oriented Version
    cout << "\nOBJECT-ORIENTED PROGRAMMING\n";

    SmartCard card(10000);

    for (long long fare : fares)
    {
        if (card.deduct(fare))
        {
            cout << "Fare Rs " << fare / 100
                 << ".00 deducted successfully\n";
        }
        else
        {
            cout << "Journey Denied (Low Balance)\n";
        }

        cout << "Balance Rs "
             << card.getBalance() / 100
             << ".00\n";
    }

    return 0;
}
