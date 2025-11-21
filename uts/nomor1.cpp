 //Author: Trisna Kusuma Ramadhany
 // NIM: 103112400277
 //Deskripsi: Program untuk menambahkan nama serta nenghitung angka genap dalam nama tersebut.
#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

void insertAkhir(string nama) {
    Node* n = new Node{nama, nullptr};
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

void deleteNama(string target) {
    if (!head) return;
    Node* t = head, *p = nullptr;

    if (t->nama == target) { head = t->next; delete t; return; }

    while (t && t->nama != target) { p = t; t = t->next; }

    if (t) { p->next = t->next; delete t; }
}

void view() {
    Node* t = head;
    while (t) { cout << t->nama << " "; t = t->next; }
    cout << endl;
}

void hitungGenap() {
    int c = 0;
    for (Node* t = head; t; t = t->next)
        if (t->nama.length() % 2 == 0) c++;
    cout << "Jumlah nama dengan huruf genap: " << c << endl;
}

int main() {
    int pil; string nama;
    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> pil;
        if (pil == 1) { cout << "Masukkan nama: "; cin >> nama; insertAkhir(nama); }
        else if (pil == 2) { cout << "Nama untuk delete: "; cin >> nama; deleteNama(nama); }
        else if (pil == 3) view();
        else if (pil == 4) hitungGenap();
    } while (pil != 0);
}
