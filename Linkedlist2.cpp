#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        data = node_data;
        next = nullptr;
    }
};

void printLinkedList(SinglyLinkedListNode* head) {

    // Traverse the linked list
    while (head != nullptr) {
        cout << head->data << endl;
        head = head->next;
    }
}

int main() {

    int n;
    cin >> n;

    SinglyLinkedListNode* head = nullptr;
    SinglyLinkedListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {

        int data;
        cin >> data;

        SinglyLinkedListNode* newNode =
            new SinglyLinkedListNode(data);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printLinkedList(head);

    return 0;
}