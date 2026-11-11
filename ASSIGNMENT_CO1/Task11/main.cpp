
#include <iostream>
#include <array>
#include <iomanip>
#include <string>
using namespace std;

enum class Zone {
    Inner = 0,
    Middle = 1,
    Outer = 2
};

constexpr array<long long, 3> BASE_FARE = {
    1000, 2000, 3000
};

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(Zone zone, int hour) {
    int index = static_cast<int>(zone);

    if (index < 0 || index >= 3 ||
        hour < 0 || hour > 23) {
        return -1;
    }

    long long fare = BASE_FARE[index];

    if (isPeakHour(hour)) {
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;
    }

    return fare;
}

class SmartCard {
private:
    long long balance;

public:
    explicit SmartCard(long long initialBalance)
        : balance(initialBalance) {}

    bool canTravel(long long fare) const {
        return fare >= 0 &&
               balance >= fare &&
               balance - fare >= MIN_BALANCE_PAISE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare)) {
            return false;
        }

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

void printMoney(long long paise) {
    cout << "Rs " << paise / 100 << "."
         << setw(2) << setfill('0')
         << paise % 100 << setfill(' ');
}

int main() {
    cout << "FINAL METRO FARE SYSTEM DESIGN\n";
    cout << "------------------------------\n";

    SmartCard card(10000);

    struct Trip {
        Zone zone;
        int hour;
        string description;
    };

    Trip trips[] = {
        {Zone::Inner, 11, "Inner Off-Peak"},
        {Zone::Outer, 18, "Outer Peak"},
        {Zone::Middle, 12, "Middle Off-Peak"}
    };

    for (const Trip& trip : trips) {
        long long fare = calculateFare(
            trip.zone, trip.hour
        );

        cout << "\n" << trip.description << "\n";
        cout << "Fare: ";

        if (fare >= 0) {
            printMoney(fare);
        } else {
            cout << "Invalid fare";
        }

        if (card.deduct(fare)) {
            cout << "\nJourney: Allowed";
        } else {
            cout << "\nJourney: Denied";
        }

        cout << "\nRemaining balance: ";
        printMoney(card.getBalance());
        cout << '\n';
    }

    return 0;
}
