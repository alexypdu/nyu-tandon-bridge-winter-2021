#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

class Money {
public:
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double get_value() const;
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    Money& operator +=(const Money& rhs);
    friend istream& operator >>(istream& ins, Money& amount);
    friend ostream& operator <<(ostream& outs, const Money& amount);
private:
    long all_cents;
};

class Check {
public:
    Check(int number, long dollars, int cents, bool is_cashed);
    Check(int number, long dollars, bool is_cashed);
    Check();
    int get_number() const;
    Money get_amount() const;
    bool get_is_cashed() const;
    void set_number(int number);
    void set_amount(const Money& amount);
    void set_is_cashed(bool is_cashed);
    friend bool operator <(const Check& lhs, const Check& rhs);
    friend istream& operator >>(istream& ins, Check& check);
    friend ostream& operator <<(ostream& outs, const Check& check);
private:
    int number;
    Money amount;
    bool is_cashed;
};

int digit_to_int(char c);
Money get_total_cashed_checks(const Check checks[], int num_of_checks);
Money get_total_uncashed_checks(const Check checks[], int num_of_checks);
Money get_total_deposits(const Money deposits[], int num_of_deposits);
void list_cashed_checks(const Check checks[], int num_of_checks);
void list_uncashed_checks(const Check checks[], int num_of_checks);

int main() {
    int num_of_checks;

    cout << "Welcome to my checkbook balancing program!\n"
         << "Please enter your checks, each in a separate line.\n"
         << "For each check, please enter the number of the check, the amount of the check, "
         << "and whether or not it has been cashed (separated by a space).\n"
         << "The number of a check should be a non-negative integer.\n"
         << "The amount of a check should be in the format: $##.##.\n"
         << "Enter (y/yes/Y) if a check has been cashed; enter (n/no/N) otherwise.\n"
         << "E.g. \"1 $5.00 Y\", \"13 $25.50 no\"\n"
         << "Enter the number of your checks: ";
    cin >> num_of_checks;
    cout << "Enter your checks:\n";

    Check* checks = new Check[num_of_checks];

    for (int i = 0; i < num_of_checks; ++i) {
        cin >> checks[i];
    }

    int num_of_deposits;

    cout << "Please enter your deposits, each in a separate line.\n"
         << "The amount of a deposit should be in the format: $##.##.\n"
         << "Enter the number of your deposits: ";
    cin >> num_of_deposits;
    cout << "Enter your deposits:\n";

    Money* deposits = new Money[num_of_deposits];

    for (int i = 0; i < num_of_deposits; ++i) {
        cin >> deposits[i];
    }

    Money old_balance;

    cout << "Please enter your old account balance ($##.##): ";
    cin >> old_balance;
    cout << endl;

    Money total_cashed_checks, total_uncashed_checks, total_deposits, calculated_bank_balance, calculated_customer_balance;
    total_cashed_checks = get_total_cashed_checks(checks, num_of_checks);
    total_uncashed_checks = get_total_uncashed_checks(checks, num_of_checks);
    total_deposits = get_total_deposits(deposits, num_of_deposits);
    calculated_bank_balance = old_balance - total_cashed_checks + total_deposits;
    calculated_customer_balance = old_balance - (total_cashed_checks + total_uncashed_checks) + total_deposits;

    cout << "The total of the checks cashed: " << total_cashed_checks << endl
         << "The total of the deposits: " << total_deposits << endl
         << "The new account balance according to the bank should be: " << calculated_bank_balance << endl
         << "The new account balance according to the customer should be: " << calculated_customer_balance << endl
         << "The difference between the two balances: " << total_uncashed_checks << "\n\n";

    sort(checks, checks + num_of_checks);
    list_cashed_checks(checks, num_of_checks);
    cout << endl;
    list_uncashed_checks(checks, num_of_checks);

    delete [] checks;
    delete [] deposits;

    return 0;
}

Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }

    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100) {}

Money::Money() : all_cents(0) {}

double Money::get_value() const {
    return all_cents * 0.01;
}

Money operator +(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;

    return temp;
}

Money operator -(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;

    return temp;
}

Money operator -(const Money& amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;

    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return amount1.all_cents == amount2.all_cents;
}

Money & Money::operator+=(const Money& rhs) {
    this->all_cents += rhs.all_cents;

    return *this;
}

istream& operator >>(istream& ins, Money& amount) {
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> one_char;

    if (one_char == '-') {
        negative = true;
        ins >> one_char; // read '$'
    } else {
        negative = false;
    }

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;

    if (negative) {
        amount.all_cents = -amount.all_cents;
    }

    return ins;
}

ostream& operator <<(ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0) {
        outs << "-$" << dollars << '.';
    } else {
        outs << '$' << dollars << '.';
    }

    if (cents < 10) {
        outs << '0';
    }

    outs << cents;

    return outs;
}

Check::Check(int number, long dollars, int cents, bool is_cashed) : number(number), amount(Money(dollars, cents)), is_cashed(is_cashed) {}

Check::Check(int number, long dollars, bool is_cashed) : number(number), amount(Money(dollars)), is_cashed(is_cashed) {}

Check::Check() : number(0), amount(Money()), is_cashed(false) {}

int Check::get_number() const {
    return number;
}

Money Check::get_amount() const {
    return amount;
}

bool Check::get_is_cashed() const {
    return is_cashed;
}

void Check::set_number(int number) {
    this->number = number;
}

void Check::set_amount(const Money& amount) {
    this->amount = amount;
}

void Check::set_is_cashed(bool is_cashed) {
    this->is_cashed = is_cashed;
}

bool operator <(const Check& lhs, const Check& rhs) {
    return lhs.number < rhs.number;
}

istream& operator >>(istream& ins, Check& check) {
    string is_cashed;

    ins >> check.number >> check.amount >> is_cashed;

    if (is_cashed == "y" || is_cashed == "yes" || is_cashed == "Y") {
        check.is_cashed = true;
    } else if (is_cashed == "n" || is_cashed == "no" || is_cashed == "N") {
        check.is_cashed = false;
    } else {
        cout << "Error illegal form for whether or not a check has been cashed\n";
        exit(1);
    }

    return ins;
}

ostream& operator <<(ostream& outs, const Check& check) {
    outs << check.number << ' ' << check.amount << ' ';

    if (check.is_cashed) {
        outs << "Cashed";
    } else {
        outs << "Not cashed";
    }

    return outs;
}

int digit_to_int(char c) {
    return static_cast<int>(c) - static_cast<int>('0');
}

Money get_total_cashed_checks(const Check checks[], int num_of_checks) {
    Money temp;

    for (int i = 0; i < num_of_checks; ++i) {
        if (checks[i].get_is_cashed()) {
            temp += checks[i].get_amount();
        }
    }

    return temp;
}

Money get_total_uncashed_checks(const Check checks[], int num_of_checks) {
    Money temp;

    for (int i = 0; i < num_of_checks; ++i) {
        if (!checks[i].get_is_cashed()) {
            temp += checks[i].get_amount();
        }
    }

    return temp;
}

Money get_total_deposits(const Money deposits[], int num_of_deposits) {
    Money temp;

    for (int i = 0; i < num_of_deposits; ++i) {
        temp += deposits[i];
    }

    return temp;
}

void list_cashed_checks(const Check checks[], int num_of_checks) {
    cout << "List of cashed checks (number amount status):\n";

    for (int i = 0; i < num_of_checks; ++i) {
        if (checks[i].get_is_cashed()) {
            cout << checks[i] << endl;
        }
    }
}

void list_uncashed_checks(const Check checks[], int num_of_checks) {
    cout << "List of uncashed checks (number amount status):\n";

    for (int i = 0; i < num_of_checks; ++i) {
        if (!checks[i].get_is_cashed()) {
            cout << checks[i] << endl;
        }
    }
}
