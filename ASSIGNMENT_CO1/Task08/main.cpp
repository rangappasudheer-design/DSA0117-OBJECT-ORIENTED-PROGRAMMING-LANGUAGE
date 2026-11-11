#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Safely read an integer and recover from invalid input.
int readInt(const string& message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
            return value;

        cout << "Invalid input! Please enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    const int MIN_BALANCE_PAISE = 5000;

    cout << "===== NAMMA METRO SMART CARD =====\n";

    int zone = readInt(
        "Enter zone (1-Inner, 2-Middle, 3-Outer): ");

    while (zone < 1 || zone > 3)
    {
        cout << "Invalid zone! Enter 1, 2 or 3.\n";
        zone = readInt("Enter zone: ");
    }

    int hour = readInt("Enter journey hour (0-23): ");

    while (hour < 0 || hour > 23)
    {
        cout << "Invalid hour! Enter 0 to 23.\n";
        hour = readInt("Enter journey hour: ");
    }

    int balanceRupees = readInt("Enter card balance in rupees: ");

    while (balanceRupees < 0)
    {
        cout << "Balance cannot be negative.\n";
        balanceRupees = readInt("Enter card balance: ");
    }

    // Store money in integer paise.
    long long balance = balanceRupees * 100LL;

    int baseFare;

    switch (zone)
    {
        case 1:
            baseFare = 1000;
            break;

        case 2:
            baseFare = 2000;
            break;

        case 3:
            baseFare = 3000;
            break;

        default:
            baseFare = 0;
    }

    // Peak hours: 8-10 AM and 5-8 PM.
    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    long long fare = baseFare;

    if (peak)
    {
        fare = fare * 120 / 100;
    }

    cout << fixed << setprecision(2);

    cout << "\n========== JOURNEY REPORT ==========\n";

    cout << "Zone: ";
    if (zone == 1)
        cout << "Inner\n";
    else if (zone == 2)
        cout << "Middle\n";
    else
        cout << "Outer\n";

    cout << "Journey hour: " << setw(2) << setfill('0')
         << hour << ":00\n";

    cout << setfill(' ');

    cout << "Peak hour: " << (peak ? "Yes" : "No") << '\n';

    cout << "Fare: Rs "
         << static_cast<double>(fare) / 100.0 << '\n';

    if (balance - fare >= MIN_BALANCE_PAISE)
    {
        balance -= fare;
        cout << "Journey status: APPROVED\n";
    }
    else
    {
        cout << "Journey status: DENIED (Low balance)\n";
    }

    cout << "Remaining balance: Rs "
         << static_cast<double>(balance) / 100.0 << '\n';

    cout << "====================================\n";

    return 0;
}