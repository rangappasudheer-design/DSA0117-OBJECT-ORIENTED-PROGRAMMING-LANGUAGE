
#include <iostream>
#include <string>
using namespace std;

// RAII class
class Guard {
private:
    string name;

public:
    // Constructor
    explicit Guard(const string& s) {
        name = s;
        cout << name << " created ";
    }

    // Destructor
    ~Guard() {
        cout << "~" << name << " ";
    }
};

// Function that throws an exception
void f() {

    Guard g("f");

    throw 42;
}

int main() {

    try {

        Guard m("main");

        f();

        cout << "not printed ";
    }

    catch (int x) {

        cout << "caught " << x;
    }

    catch (...) {

        cout << "other";
    }

    cout << endl;

    return 0;
}
