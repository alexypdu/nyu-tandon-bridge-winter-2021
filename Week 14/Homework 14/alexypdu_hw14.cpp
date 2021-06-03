#include <iostream>
#include <vector>
using namespace std;

vector<int> find_min_max(const vector<int>& v, int low, int high);
vector<int> merge_min_max(const vector<int>& min_max_1, const vector<int>& min_max_2);

int main() {
    vector<int> v = {9, 4, 8, 7, 3, 0, 6, 5};
    vector<int> min_max = find_min_max(v, 0, v.size() - 1);

    cout << "min = " << min_max[0] << ", max = " << min_max[1];

    return 0;
}

vector<int> find_min_max(const vector<int>& v, int low, int high) {
    if (low == high) {
        vector<int> min_max(2, v[low]);

        return min_max;
    } else {
        int mid = low + (high - low) / 2;
        vector<int> min_max_1 = find_min_max(v, low, mid);
        vector<int> min_max_2 = find_min_max(v, mid + 1, high);

        return merge_min_max(min_max_1, min_max_2);
    }
}

vector<int> merge_min_max(const vector<int>& min_max_1, const vector<int>& min_max_2) {
    vector<int> min_max(2);
    min_max[0] = min(min_max_1[0], min_max_2[0]);
    min_max[1] = max(min_max_1[1], min_max_2[1]);

    return min_max;
}
