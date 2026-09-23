#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}






void deleteNode(Node*& head, int position) {

    if (head == NULL) {
        cout << "Linked List is empty" << endl;
        return;
    }

    
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }



    Node* temp = head;

    
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }



    
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position" << endl;
        return;
    }



    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;
}



void display(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Node* head = NULL;
    int n, value, position;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(head, value);
    }

    cout << "Original Linked List: ";
    display(head);

    cout << "Enter position to delete: ";
    cin >> position;

    deleteNode(head, position);

    cout << "After deletion: ";
    display(head);

    return 0;
}