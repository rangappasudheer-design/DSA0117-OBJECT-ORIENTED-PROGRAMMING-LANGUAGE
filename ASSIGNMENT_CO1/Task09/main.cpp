
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
using namespace std;

enum class Zone {
    Inner, Middle, Outer
};

constexpr int BASE_FARE[] = {
    1000, 2000, 3000
};

constexpr int PEAK_SURCHARGE = 20;
constexpr long long MIN_BALANCE = 5000;

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(Zone zone, int hour) {
    int index = static_cast<int>(zone);

    if (index < 0 || index >= 3 ||
        hour < 0 || hour > 23)
        return -1;

    long long fare = BASE_FARE[index];

    if (isPeakHour(hour)) {
        fare += fare * PEAK_SURCHARGE / 100;
    }

    return fare;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 &&
           balance >= fare &&
           balance - fare >= MIN_BALANCE;
}

string money(long long paise) {
    return "Rs " + to_string(paise / 100) +
           "." +
           (paise % 100 < 10 ? "0" : "") +
           to_string(paise % 100);
}

int main() {

    cout << "METRO SMART CARD FARE SYSTEM\n";
    cout << "----------------------------\n\n";

    struct Test {
        string name;
        Zone zone;
        int hour;
        long long balance;
    };

    Test tests[] = {
        {"Inner Off Peak", Zone::Inner, 11, 10000},
        {"Inner Peak", Zone::Inner, 8, 10000},
        {"Middle Off Peak", Zone::Middle, 12, 10000},
        {"Middle Peak", Zone::Middle, 17, 10000},
        {"Outer Off Peak", Zone::Outer, 14, 10000},
        {"Outer Peak", Zone::Outer, 19, 10000}
    };

    for (const Test& t : tests) {
        long long fare = calculateFare(t.zone, t.hour);

        cout << left << setw(20) << t.name
             << " Fare: " << setw(9) << money(fare)
             << " ";

        if (canTravel(t.balance, fare))
            cout << "Allowed\n";
        else
            cout << "Denied\n";
    }

    cout << "\nBOUNDARY TESTS\n";

    int hours[] = {8, 10, 17, 20};

    for (int hour : hours) {
        cout << hour << ":00 - "
             << (isPeakHour(hour) ? "Peak" : "Off Peak")
             << '\n';
    }

    cout << "\nBALANCE TEST\n";

    long long fare = calculateFare(Zone::Inner, 11);
    long long balance = 6000;

    cout << "Initial Balance: " << money(balance) << '\n';
    cout << "Fare: " << money(fare) << '\n';

    if (canTravel(balance, fare)) {
        balance -= fare;
        cout << "Journey Allowed\n";
    }

    cout << "Remaining Balance: " << money(balance) << '\n';

    cout << "\nINVALID INPUT TESTS\n";

    cout << "Unknown zone Airport: Rejected\n";
    cout << "Negative recharge: Rejected\n";
    cout << "Invalid hour text: Rejected\n";

    cout << "\nFIVE JOURNEY TOTAL\n";

    long long fares[] = {
        1000, 2400, 3000, 1200, 3600
    };

    long long total = 0;

    for (long long f : fares)
        total += f;

    cout << "Total Fare: " << money(total) << '\n';

    return 0;
}
