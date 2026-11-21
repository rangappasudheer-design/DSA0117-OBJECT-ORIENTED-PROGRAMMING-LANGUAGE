
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Custom exception class
class HospitalError : public runtime_error {
public:
    HospitalError(string message)
        : runtime_error(message) {
    }
};

// Function to validate bill amount
void validateBill(double amount) {

    if (amount < 0) {
        throw invalid_argument("Negative bill amount");
    }

    cout << "Bill amount is valid" << endl;
}

// Function to check insurance claim
void checkInsurance(double claim, double limit) {

    if (claim > limit) {
        throw HospitalError("Claim exceeds insurance limit");
    }

    cout << "Insurance claim approved" << endl;
}

// Function to check package
void checkPackage(string packageName) {

    if (packageName != "General" &&
        packageName != "Emergency") {

        throw HospitalError("Unknown package");
    }

    cout << "Package is valid" << endl;
}

// Function to check patient record
void checkPatient(bool found) {

    if (!found) {
        throw HospitalError("Patient record not found");
    }

    cout << "Patient record found" << endl;
}

int main() {

    cout << "HOSPITAL BILLING SYSTEM\n";
    cout << "-----------------------\n";

    // Test 1: Negative bill
    try {
        validateBill(-500);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Test 2: Insurance claim
    try {
        checkInsurance(50000, 30000);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Test 3: Unknown package
    try {
        checkPackage("Premium");
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Test 4: Missing patient
    try {
        checkPatient(false);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Program completed successfully" << endl;

    return 0;
}
