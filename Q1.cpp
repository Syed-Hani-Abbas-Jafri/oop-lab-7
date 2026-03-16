#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNo, string name, double bal, string type)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
        accountType = type;
    }

    virtual ~Account() {}

    void deposit(double amount)
    {
        if (amount <= 0) {
            cout << "Insufficient amount!" << endl;
            return;
        }
        balance += amount;
        cout << "Deposited   : " << amount << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= 0) {
            cout << "Invalid amount!" << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient Balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn   : " << amount << endl;
    }

    virtual void calculateInterest()
    {
        cout << "No fixed interest rule for this account." << endl;
    }

    virtual void printStatement()
    {
        cout << "\nAccount Statement" << endl;
        cout << "Account Holder  : " << accountHolderName << endl;
        cout << "Account Number  : " << accountNumber     << endl;
        cout << "Balance         : " << balance           << endl;
        cout << "Account Type    : " << accountType       << endl;
    }

    void getAccountInfo()
    {
        cout << "Account Holder  : " << accountHolderName << endl;
        cout << "Account Number  : " << accountNumber     << endl;
    }
};


class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNo, string name, double bal, double rate, double minBal)
        : Account(accNo, name, bal, "Savings")
    {
        interestRate = rate;
        minimumBalance = minBal;
    }

    void withdraw(double amount) override
    {
        if (amount <= 0) {
            cout << "Invalid amount!" << endl;
            return;
        }
        if (balance - amount < minimumBalance) {
            cout << "Cannot withdraw. Minimum balance required!" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawn from Savings : " << amount << endl;
    }

    void calculateInterest() override
    {
        double interest = balance * interestRate / 100.0;
        balance += interest;
        cout << "Savings Interest Added : " << interest << endl;
    }

    void printStatement() override
    {
        Account::printStatement();
        cout << "Interest Rate   : " << interestRate    << "%" << endl;
        cout << "Minimum Balance : " << minimumBalance  << endl;
    }
};


class CheckingAccount : public Account {
public:
    CheckingAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal, "Checking") {}

    void calculateInterest() override
    {
        cout << "Checking accounts do not earn interest." << endl;
    }

    void printStatement() override
    {
        Account::printStatement();
    }
};


class FixedDepositAccount : public Account {
private:
    string maturityDate;
    double fixedInterestRate;
    bool   matured;

public:
    FixedDepositAccount(int accNo, string name, double bal, string date, double rate)
        : Account(accNo, name, bal, "Fixed Deposit")
    {
        maturityDate = date;
        fixedInterestRate = rate;
        matured = false;
    }

    void calculateInterest() override
    {
        double interest = balance * fixedInterestRate / 100.0;
        balance += interest;
        matured = true;
        cout << "Fixed Deposit Interest Added : " << interest << endl;
    }

    void withdraw(double amount) override
    {
        if (!matured) {
            cout << "Withdrawal not allowed before maturity date!" << endl;
            return;
        }
        Account::withdraw(amount);
    }

    void printStatement() override
    {
        Account::printStatement();
        cout << "Maturity Date   : " << maturityDate      << endl;
        cout << "Fixed Rate      : " << fixedInterestRate << "%" << endl;
        cout << "Matured         : " << (matured ? "Yes" : "No") << endl;
    }
};


int main()
{
    SavingsAccount      s1(101, "Hassan", 5000, 5.0, 1000);
    CheckingAccount     c1(102, "Ali",    3000);
    FixedDepositAccount f1(103, "Ahmed",  10000, "01-12-2027", 7.0);

    cout << "\n/-/-/-/-/-/- savings account /-/-/-/-/-/-" << endl;
    s1.deposit(1000);
    s1.withdraw(2000);
    s1.withdraw(5000);
    s1.calculateInterest();
    s1.printStatement();

    cout << "\n/-/-/-/-/-/- checking account /-/-/-/-/-/-" << endl;
    c1.deposit(500);
    c1.withdraw(1000);
    c1.withdraw(5000);
    c1.calculateInterest();
    c1.printStatement();

    cout << "\n/-/-/-/-/-/- fixed deposit account /-/-/-/-/-/-" << endl;
    f1.withdraw(1000);
    f1.calculateInterest();
    f1.withdraw(2000);
    f1.printStatement();

    return 0;
}
