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

SinglyLinkedListNode* insertNodeAtTail(
    SinglyLinkedListNode* head, int data) {

    
    SinglyLinkedListNode* newNode =
        new SinglyLinkedListNode(data);

    
    if (head == nullptr) {
        return newNode;
    }

    
    SinglyLinkedListNode* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    
    temp->next = newNode;

    return head;
}

void printList(SinglyLinkedListNode* head) {
    while (head != nullptr) {
        cout << head->data << endl;
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;

    SinglyLinkedListNode* head = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;

        head = insertNodeAtTail(head, data);
    }

    printList(head);

    return 0;
}