#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue {
    vector<T> queue;
    int front;
    int _size;
public:
    void enqueue(T item) {
        queue.push_back(item);
        _size++;
    }
    T dequeue() {
        T temp = queue[front++];
        _size--;

        if (empty()) {
            clear();
        }

        return temp;
    }
    T top() {
        return queue[front];
    }
    int size() {
        return _size;
    }
    bool empty() {
        return _size == 0;
    }
    void clear() {
        queue.clear();
        front = 0;
    }
};

int main() {
    Queue<int> q;

    for (int i = 0; i < 10; ++i) {
        q.enqueue(i);
    }

    for (int j = 0; j < 10; ++j) {
        q.dequeue();
    }

    cout << "size: " << q.size() << endl;

    while (q.size()) {
        cout << q.dequeue() << " ";
    }

    for (int i = 0; i < 12; ++i) {
        q.enqueue(i);
    }

    for (int j = 0; j < 7; ++j) {
        q.dequeue();
    }

    cout << "size: " << q.size() << endl;

    while (q.size()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}
