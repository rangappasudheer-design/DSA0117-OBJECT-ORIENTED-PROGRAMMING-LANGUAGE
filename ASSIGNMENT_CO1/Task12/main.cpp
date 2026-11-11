
#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

enum class Zone {
    Inner, Middle, Outer, Airport
};

constexpr array<long long, 4> BASE_FARE = {
    1000, 2000, 3000, 6000
};

constexpr int PEAK_SURCHARGE = 20;
constexpr int WEEKEND_DISCOUNT = 10;
constexpr long long MIN_BALANCE = 5000;

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(
    Zone zone, int hour, bool weekend
) {
    int index = static_cast<int>(zone);

    if (index < 0 || index >= 4 ||
        hour < 0 || hour > 23) {
        return -1;
    }

    long long fare = BASE_FARE[index];

    // Weekend discount takes priority over peak surcharge.
    if (weekend) {
        fare -= fare * WEEKEND_DISCOUNT / 100;
    }
    else if (isPeakHour(hour)) {
        fare += fare * PEAK_SURCHARGE / 100;
    }

    return fare;
}

class MonthlyPass {
private:
    Zone firstZone;
    Zone secondZone;
    bool active;

public:
    MonthlyPass(Zone first, Zone second)
        : firstZone(first),
          secondZone(second),
          active(true) {}

    bool allows(Zone zone) const {
        return active &&
              (zone == firstZone || zone == secondZone);
    }
};

class SmartCard {
private:
    long long balance;

public:
    explicit SmartCard(long long initialBalance)
        : balance(initialBalance) {}

    bool travel(
        Zone zone,
        int hour,
        bool weekend,
        const MonthlyPass* pass = nullptr
    ) {
        // Monthly pass covers journeys in its two zones.
        if (pass != nullptr && pass->allows(zone)) {
            cout << "Monthly pass used. No fare deducted.\n";
            return true;
        }

        long long fare =
            calculateFare(zone, hour, weekend);

        if (fare < 0) {
            cout << "Invalid journey.\n";
            return false;
        }

        if (balance - fare < MIN_BALANCE) {
            cout << "Journey denied: minimum balance rule.\n";
            return false;
        }

        balance -= fare;

        cout << "Fare: ";
        printMoney(fare);
        cout << "\n";

        return true;
    }

    long long getBalance() const {
        return balance;
    }

    static void printMoney(long long paise) {
        cout << "Rs " << paise / 100 << "."
             << setw(2) << setfill('0')
             << paise % 100 << setfill(' ');
    }
};

void printMoney(long long paise) {
    SmartCard::printMoney(paise);
}

int main() {
    cout << "UPDATED METRO FARE SYSTEM\n";
    cout << "-------------------------\n";

    SmartCard card(10000);

    // Monthly pass allows Inner and Middle zones.
    MonthlyPass pass(Zone::Inner, Zone::Middle);

    cout << "\n1. Inner zone, weekend:\n";
    card.travel(Zone::Inner, 11, true);

    cout << "\n2. Outer zone, weekday peak:\n";
    card.travel(Zone::Outer, 18, false);

    cout << "\n3. Middle zone, weekend peak:\n";
    card.travel(Zone::Middle, 18, true, &pass);

    cout << "\n4. Airport zone, weekday off-peak:\n";
    card.travel(Zone::Airport, 12, false);

    cout << "\nFinal balance: ";
    printMoney(card.getBalance());
    cout << '\n';

    return 0;
}
