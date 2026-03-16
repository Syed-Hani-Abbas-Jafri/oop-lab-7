#include <iostream>
using namespace std;

class Currency {
protected:
    double amt;
    string code;
    string symbol;
    double rate;

public:
    Currency(double a, string c, string s, double r)
    {
        amt    = a;
        code   = c;
        symbol = s;
        rate   = r;
    }

    virtual double convertToBase()
    {
        return amt * rate;
    }

    double convertTo(Currency &target)
    {
        return convertToBase() / target.rate;
    }

    virtual void displayCurrency()
    {
        cout << "Currency : " << code        << endl;
        cout << "Amount   : " << symbol << amt << endl;
        cout << "Rate     : " << rate         << endl;
    }
};


class Dollar : public Currency {
public:
    Dollar(double a) : Currency(a, "USD", "$", 1.0) {}

    double convertToBase() override
    {
        return amt;
    }

    void displayCurrency() override
    {
        cout << "US Dollar : $" << amt << endl;
    }
};


class Euro : public Currency {
public:
    Euro(double a) : Currency(a, "EUR", "€", 1.1) {}

    double convertToBase() override
    {
        return amt * rate;
    }

    void displayCurrency() override
    {
        cout << "Euro : €" << amt << endl;
    }
};


class Rupee : public Currency {
public:
    Rupee(double a) : Currency(a, "PKR", "Rs", 0.0036) {}

    double convertToBase() override
    {
        return amt * rate;
    }

    void displayCurrency() override
    {
        cout << "Rupee : Rs " << amt << endl;
    }
};


int main()
{
    Dollar usd(100);
    Euro   eur(100);
    Rupee  pkr(10000);

    cout << "\n/-/-/-/-/-/- display currencies /-/-/-/-/-/-" << endl;
    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "\n/-/-/-/-/-/- conversions /-/-/-/-/-/-" << endl;
    cout << "100 USD to EUR    : " << usd.convertTo(eur) << endl;
    cout << "100 EUR to USD    : " << eur.convertTo(usd) << endl;
    cout << "10000 PKR to USD  : " << pkr.convertTo(usd) << endl;

    return 0;
}
