
#include <iostream>
#include <string>
using namespace std;

// Part 1: Static member and constructor
class Token {
    static int next;
    int id;

public:
    Token() {
        id = ++next;
    }

    int get() const {
        return id;
    }

    static int issued() {
        return next - 100;
    }
};

int Token::next = 100;

// Part 2: BusTicket class
class BusTicket {
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    explicit BusTicket(const string& n) : seat(0), name(n) {
        // TODO 1: Assign a seat if capacity is available.
        if (issued < CAPACITY) {
            ++issued;
            seat = issued;
        }
    }

    static int count() {
        // TODO 2: Return the number of seats issued.
        return issued;
    }

    void print() const {
        cout << name << ": "
             << (seat ? "Seat " + to_string(seat)
                      : string("Waiting"))
             << '\n';
    }
};

int BusTicket::issued = 0;

int main() {
    cout << "TOKEN OUTPUT" << '\n';

    Token counter[3];
    Token extra;

    cout << counter[0].get() << ' '
         << counter[2].get() << ' '
         << extra.get() << ' '
         << Token::issued() << '\n';

    cout << "\nBUS TICKETS" << '\n';

    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (const BusTicket& t : trip) {
        t.print();
    }

    cout << "Issued: " << BusTicket::count() << '\n';

    return 0;
}
