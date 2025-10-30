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

// Fungsi untuk menambah node di depan
void insertFirst(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;

    if (head == NULL) {
        newNode->next = NULL;
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Cetak list dari depan ke belakang
void printForward() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi menghapus node pertama dengan nilai tertentu
void deleteByValue(int value) {
    Node* current = head;

    // cari node yang memiliki data == value
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    // jika tidak ditemukan
    if (current == NULL) {
        cout << "Nilai " << value << " tidak ditemukan" << endl;
        return;
    }

    // jika node di awal
    if (current == head) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL; // list kosong
    }
    // jika node di akhir
    else if (current == tail) {
        tail = tail->prev;
        tail->next = NULL;
    }
    // jika node di tengah
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Nilai " << value << " berhasil dihapus" << endl;
}

// Fungsi menghapus semua elemen list
void deleteAll() {
    Node* current = head;
    int count = 0;

    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
        count++;
    }

    head = tail = NULL;
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}

// Main program
int main() {
    cout << "TASK 1: DELETE OPERATIONS\n";

    // List awal: 2 3 2 1
    insertFirst(1);
    insertFirst(2);
    insertFirst(3);
    insertFirst(2);

    cout << "List awal: ";
    printForward();

    deleteByValue(2);
    cout << "Setelah deleteByValue(2): ";
    printForward();

    deleteByValue(5);
    cout << "List tetap: ";
    printForward();

    // Tambah data baru
    insertFirst(1);
    insertFirst(2);
    insertFirst(3);
    insertFirst(4);
    insertFirst(5);

    cout << "List setelah tambah data: ";
    printForward();

    deleteAll();

    return 0;
}
