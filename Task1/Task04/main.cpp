
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    string transactions[10];
    int count;

public:
    SavingsAccount(int accNo, double initialBalance)
    {
        accountNumber = accNo;
        balance = initialBalance;
        count = 0;
    }

    // Deposit function defined inside class
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit amount\n";
            return;
        }

        balance += amount;

        string record = "Deposit: " + to_string(amount);

        if (count < 10)
        {
            transactions[count++] = record;
        }
        else
        {
            for (int i = 1; i < 10; i++)
            {
                transactions[i - 1] = transactions[i];
            }

            transactions[9] = record;
        }
    }

    // Member functions defined outside class
    void withdraw(double amount);

    void miniStatement() const;

    void displayBalance() const
    {
        cout << "Account Number: "
             << accountNumber << endl;

        cout << "Current Balance: "
             << balance << endl;
    }
};

// Withdrawal function
void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        cout << "Invalid withdrawal\n";
        return;
    }

    balance -= amount;

    string record = "Withdrawal: " + to_string(amount);

    if (count < 10)
    {
        transactions[count++] = record;
    }
    else
    {
        for (int i = 1; i < 10; i++)
        {
            transactions[i - 1] = transactions[i];
        }

        transactions[9] = record;
    }
}

// Mini statement function
void SavingsAccount::miniStatement() const
{
    cout << "\nMini Statement\n";

    for (int i = 0; i < count; i++)
    {
        cout << transactions[i] << endl;
    }
}

int main()
{
    SavingsAccount account(1001, 5000);

    account.displayBalance();

    account.deposit(1000);
    account.deposit(2000);

    account.withdraw(500);
    account.deposit(1500);

    account.withdraw(1000);

    account.displayBalance();

    account.miniStatement();

    return 0;
}
