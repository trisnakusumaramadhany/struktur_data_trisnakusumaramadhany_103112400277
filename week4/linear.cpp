#include <iostream>
using namespace std;

// Definisi node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk pencarian linear
Node* linearsearch(Node* head, int key) {
    Node* current = head; 

    while (current != nullptr) { 
        if (current->data == key)
            return current; 
        current = current->next; 
    }

    return nullptr; // tidak ditemukan
}

void append(Node*& head, int value) {
    Node* newnode = new Node{value, nullptr}; 

    if (!head)
        head = newnode; 
    else {
        Node* temp = head;
        while (temp->next) 
            temp = temp->next;
        temp->next = newnode; 
    }
}

int main() {
    Node* head = nullptr; 

    append(head, 10); append(head, 20);append(head, 30);

    Node* result = linearsearch(head, 20);
    cout << (result ? "found" : "not found") << endl;

    return 0;
}
