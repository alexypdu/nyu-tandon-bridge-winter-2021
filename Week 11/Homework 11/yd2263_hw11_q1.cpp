#include <iostream>
using namespace std;

void print_triangle(int n);
void print_opposite_triangles(int n);
void print_ruler(int n);

int main() {
    cout << "print_triangle(4):\n";
    print_triangle(4);
    cout << endl;
    cout << "print_opposite_triangles(4):\n";
    print_opposite_triangles(4);
    cout << endl;
    cout << "print_ruler(4):\n";
    print_ruler(4);

    return 0;
}

void print_triangle(int n) {
    if (n < 1) {
        return;
    } else {
        print_triangle(n - 1);

        for (int i = 0; i < n; i++) {
            cout << '*';
        }

        cout << endl;
    }
}

void print_opposite_triangles(int n) {
    if (n < 1) {
        return;
    } else {
        for (int i = 0; i < n; i++) {
            cout << '*';
        }

        cout << endl;
        print_opposite_triangles(n - 1);

        for (int i = 0; i < n; i++) {
            cout << '*';
        }

        cout << endl;
    }
}

void print_ruler(int n) {
    if (n < 1) {
        return;
    } else {
        print_ruler(n - 1);

        for (int i = 0; i < n; i++) {
            cout << '-';
        }

        cout << endl;
        print_ruler(n - 1);
    }
}
