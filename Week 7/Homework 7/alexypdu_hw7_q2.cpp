#include <iostream>
#include <cmath>
using namespace std;

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    int num;

    cout << "Please enter a positive integer M (>= 2): ";
    cin >> num;
    cout << "All the perfect numbers between 2 and M:\n";

    for (int i = 2; i <= num; i++) {
        if (isPerfect(i)) {
            cout << i << endl;
        }
    }

    cout << "All pairs of amicable numbers that are between 2 and M:\n";

    for (int i = 2; i <= num; i++) {
        int countDivs1, sumDivs1;
        int countDivs2, sumDivs2;

        analyzeDivisors(i, countDivs1, sumDivs1);
        analyzeDivisors(sumDivs1, countDivs2, sumDivs2);

        if ((i == sumDivs2) && (i < sumDivs1)) {
            cout << '(' << i << ", " << sumDivs1 << ")\n";
        }
    }

    return 0;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    int sqrt = pow(num, 0.5), countDivs = 1 , sumDivs = 1;

    for (int i = 2; i <= sqrt; i++) {
        if (num % i == 0) {
            countDivs += 2;
            sumDivs += (i + num / i);
        }
    }

    outCountDivs = countDivs;
    outSumDivs = sumDivs;
}

bool isPerfect(int num) {
    int countDivs, sumDivs;

    analyzeDivisors(num, countDivs, sumDivs);

    return sumDivs == num;
}
