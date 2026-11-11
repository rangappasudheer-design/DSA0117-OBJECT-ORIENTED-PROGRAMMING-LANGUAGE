
#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

// TODO 1: Return the absolute difference between two times.
inline int minutesBetween(const Time& a, const Time& b) {
    int timeA = a.h * 60 + a.m;
    int timeB = b.h * 60 + b.m;

    return abs(timeA - timeB);
}

// TODO 2: Return true if a is earlier than b.
inline bool earlier(const Time& a, const Time& b) {
    if (a.h < b.h)
        return true;

    if (a.h > b.h)
        return false;

    return a.m < b.m;
}

int main() {
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << "Original Test" << '\n';
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    // Same-time test
    Time t1(12, 30);
    Time t2(12, 30);

    cout << "\nSame Time Test" << '\n';
    cout << minutesBetween(t1, t2) << ' '
         << earlier(t1, t2) << '\n';

    // Times on either side of noon
    Time morning(11, 50);
    Time afternoon(12, 10);

    cout << "\nNoon Test" << '\n';
    cout << minutesBetween(morning, afternoon) << ' '
         << earlier(morning, afternoon) << '\n';

    return 0;
}
