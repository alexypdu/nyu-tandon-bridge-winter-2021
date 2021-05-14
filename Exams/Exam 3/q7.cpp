#include <iostream>
using namespace std;

class LListNode {
public:
    int val;
    LListNode* prev;
    LListNode* next;
    LListNode(int val = 0, LListNode* prev = nullptr, LListNode* next = nullptr) : val(val), prev(prev), next(next) {}
};

void fixTheList(LListNode* first){
    if (first == nullptr) {
        return;
    }

    int i = 1;
    LListNode* prev;
    LListNode* curr;
    prev = first->prev;
    curr = first;

    while (curr != nullptr && curr->next != nullptr) { // do not need to fix dummy nodes
        if (i % 2 == 0) {
            curr->next = curr->prev;
            curr->prev = prev;
        }

        prev = curr;
        curr = curr->next;
        ++i;
    }
}

void print(LListNode* head) {
    while (head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
    }
    
    cout << endl;
}

int main() {
    LListNode* dummy_head = new LListNode();
    LListNode* first = new LListNode(1);
    LListNode* second = new LListNode(2);
    LListNode* third = new LListNode(3);
    LListNode* dummy_tail = new LListNode();

    dummy_head->next = first;
    first->prev = dummy_head;
    first->next = second;
    second->prev = third;
    second->next = first;
    third->prev = second;
    third->next = dummy_tail;
    dummy_tail->prev = third;

    fixTheList(first);
    print(dummy_head);
}
