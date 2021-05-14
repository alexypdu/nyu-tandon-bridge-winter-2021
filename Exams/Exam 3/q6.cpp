#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<double> getBusLineInfo(string busLine) {
    return {14, 0, 5.2, 3.1, 7};
}

bool bussesTooClose(string busLine) {
    vector<double> locations = getBusLineInfo(busLine);

    if (locations.size() < 2) {
        return false;
    }

    sort(locations.begin(), locations.end());

    for (int i = 0; i < locations.size() - 1; ++i) {
        if (locations[i + 1] - locations[i] < 1) {
            return true;
        }
    }

    return false;
}

int main() {
    if (bussesTooClose("B57")) {
        cout << "Too close!\n";
    } else {
        cout << "Not too close!\n";
    }
}
