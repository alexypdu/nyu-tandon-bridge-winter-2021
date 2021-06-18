#include <iostream>
#include <vector>
using namespace std;

template <class T>
class BSTNode {
public:
    T val;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode(const T& val= T(), BSTNode<T>* left = nullptr, BSTNode<T>* right = nullptr) : val(val), left(left), right(right) {}
};

bool helper(const vector<int>& v, int low, int high, BSTNode<int>* root) {
    if (root == nullptr) {
        return true;
    }

    int mid = low + (high - low) / 2;

    if (v[mid] == root->val) {
        return helper(v, low, mid - 1, root->left) && helper(v, mid + 1, high, root->right);
    } else {
        return false;
    }
}

bool treeMatchesVector(const vector<int> v, BSTNode<int>* root) {
    return helper(v, 0, v.size() - 1, root);
}


int main() {
    vector<int> v = {5, 7, 10, 12, 15, 20 ,22};
    BSTNode<int>* root = new BSTNode<int>(
      12,
      new BSTNode<int>(
        7,
        new BSTNode<int>(5),
        new BSTNode<int>(10)
      ),
      new BSTNode<int>(
        20,
        new BSTNode<int>(15),
        new BSTNode<int>(22)
      )
    );

    if (treeMatchesVector(v, root)) {
        cout << "Match!\n";
    } else {
        cout << "Not Match!\n";
    }

    return 0;
}
