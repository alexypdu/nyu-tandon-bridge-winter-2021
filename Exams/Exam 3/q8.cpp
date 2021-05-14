#include <iostream>
#include <vector>
using namespace std;

class Discount {
    double _amount;
    double _percent;
public:
    Discount() : _amount(0), _percent(0) {}
    Discount(double amount, double percent) : _amount(amount), _percent(percent) {}

    double getAmount() const {
        return _amount;
    }

    double getPercent() const {
        return _percent;
    }

    virtual double calculateFinalDiscount(double originalPrice) = 0;
};

class SinglePercentDiscount : public Discount {
public:
    SinglePercentDiscount() : Discount() {}
    SinglePercentDiscount(double percent) : Discount(0, percent) {}

    double calculateFinalDiscount(double originalPrice) {
        return originalPrice * getPercent();
    }
};

class SingleValueDiscount : public Discount {
public:
    SingleValueDiscount() : Discount() {}
    SingleValueDiscount(double amount) : Discount(amount, 0) {}

    double calculateFinalDiscount(double originalPrice) {
        return getAmount();
    }
};

class MultiDiscount : public Discount {
public:
    MultiDiscount() : Discount() {}
    MultiDiscount(double percent, double amount) : Discount(amount, percent) {}

    double calculateFinalDiscount(double originalPrice) {
        return getAmount() + (originalPrice - getAmount()) * getPercent();
    }
};

class Order {
    vector<double> prices;
    vector<Discount*> discounts;
public:
    Order() {}

    void addItem(double price, Discount* discount) {
        prices.push_back(price);
        discounts.push_back(discount);
    }

    double totalCost() {
        double res = 0;

        for (int i = 0; i < prices.size(); ++i) {
            double discount = (discounts[i] == nullptr) ? 0 : discounts[i]->calculateFinalDiscount(prices[i]);
            res += prices[i] - discount;
        }

        return res;
    }
};

int main() {
    Order firstOrder;
    SingleValueDiscount svd10(10);
    SinglePercentDiscount spd5(0.5);
    MultiDiscount md(0.102, 5.5);
    firstOrder.addItem(20, &svd10);
    firstOrder.addItem(100, &spd5);
    firstOrder.addItem(20, &md);
    firstOrder.addItem(20, nullptr);
    cout << firstOrder.totalCost() << endl;

    return 0;
}
