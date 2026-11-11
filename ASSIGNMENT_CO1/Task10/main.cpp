
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
    const long long FARE_PAISE = 3600; // Rs 36.00
    const double FARE_RUPEES = 36.00;

    const long long journeys[] = {
        20000, 500000, 3000000
    };

    cout << fixed << setprecision(2);
    cout << "TASK 10: EXPECTATION VS EXECUTION\n\n";

    cout << "Fare per journey: Rs 36.00\n";
    cout << "INT_MAX: " << INT_MAX << " paise\n\n";

    for (long long count : journeys) {
        long long totalPaise = count * FARE_PAISE;
        double totalDouble = count * FARE_RUPEES;

        cout << "Journeys: " << count << '\n';
        cout << "Integer-paise total: Rs "
             << totalPaise / 100.0 << '\n';
        cout << "Double total:         Rs "
             << totalDouble << '\n';

        cout << "Integer total in paise: "
             << totalPaise << '\n';

        if (totalPaise > INT_MAX) {
            cout << "An int storing paise would overflow.\n";
        } else {
            cout << "An int can store this paise total.\n";
        }

        cout << "Difference: Rs "
             << (totalDouble - totalPaise / 100.0)
             << "\n\n";
    }

    // Separate illustration of floating-point representation.
    double decimalTotal = 0.0;
    for (int i = 0; i < 10; ++i) {
        decimalTotal += 0.1;
    }

    cout << "Floating-point illustration:\n";
    cout << "Adding 0.1 ten times gives: "
         << setprecision(17) << decimalTotal << '\n';

    return 0;
}
