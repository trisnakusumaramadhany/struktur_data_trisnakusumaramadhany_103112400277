#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Pointer global
Node* head = NULL;
Node* tail = NULL;

// Fungsi untuk menambahkan node di belakang
void insertLast(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Fungsi untuk mencetak list dari depan ke belakang
void printForward() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi untuk mencetak list dari belakang ke depan
void printReverse() {
    Node* current = tail;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

// Fungsi untuk menyisipkan elemen sebelum data tertentu
void insertBefore(int key, int value) {
    Node* current = head;

    // cari node yang memiliki data == key
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    // jika tidak ditemukan
    if (current == NULL) {
        cout << "Elemen " << key << " tidak ditemukan!" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev != NULL) {
        current->prev->next = newNode;
    } else {
        head = newNode;
    }

    current->prev = newNode;

    cout << "Berhasil insert " << value << " sebelum " << key << endl;
}

// Fungsi utama
int main() {
    cout << "TASK 1: INSERT OPERATIONS\n";

    // Buat list awal: 1 3 2
    insertLast(1);
    insertLast(3);
    insertLast(2);

    cout << "List awal:\n";
    cout << "Forward: ";
    printForward();
    cout << "Backward: ";
    printReverse();

    // Sisipkan elemen baru
    insertBefore(2, 4);
    insertBefore(1, 5);

    cout << "\nList setelah insertBefore:\n";
    cout << "Forward: ";
    printForward();
    cout << "Backward: ";
    printReverse();

    return 0;
}
