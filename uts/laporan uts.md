UJIAN TENGAH SEMESTER
PRAKTIKUM STRUKTUR DATA
CLO 3

Identitas 

Nama: Trisna Kusuma Ramadhany

NIM: 103112400277

Kelas: 12 IF 05

1. Kode Program

Berikut adalah kode program untuk  "program C++ untuk menambah atau insert dengan nama mahasiswa,delete,melihat daftar nama mahasiswa yng sudah di insert dan hitung serta menampilkan nama mahasiswa dengan huruf genap.".

```File: main.cpp
 * Author: Trisna Kusuma Ramadhany
 * NIM: 103112400277
 * Deskripsi: Program untuk menambahkan nama serta nenghitung angka genap dalam nama tersebut.
 * yang diinput oleh user adalah nama mahasiswa
 */

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
```

2. Penjelasan Kode

Program tersebut  memakai Singly Linked List untuk menyimpan nama mahasiswa menggunakan node yang masing-masing berisi sebuah string dan pointer menuju node berikutnya. Daftar tersebut dikelola melalui pointer head, yang selalu menunjuk ke elemen pertama; ketika head bernilai nullptr, berarti list masih kosong. Proses penambahan nama dilakukan melalui fungsi insertAkhir(), yang membuat node baru dan menempatkannya di bagian paling akhir list. Jika list masih kosong, node baru tersebut langsung menjadi head; jika tidak, program menelusuri list hingga menemukan node terakhir, kemudian menyambungkan node baru di sana. Penghapusan nama dilakukan oleh fungsi deleteNama. Jika nama yang dicari berada tepat di head, node tersebut dilepas dan head dipindahkan ke node berikutnya. Jika nama berada di tengah atau akhir, program menelusuri list sambil mencatat node sebelumnya untuk memutuskan sambungan dengan benar sebelum menghapus node target.

Untuk menampilkan seluruh nama dalam list, fungsi view melakukan dari elemen pertama hingga akhir, mencetak setiap nama yang ditemukan. Sementara itu, fungsi hitungGenap bertugas menghitung berapa banyak nama yang memiliki jumlah huruf genap. Fungsi ini menelusuri seluruh node, memeriksa panjang string pada setiap nama, dan menambah penghitung apabila panjangnya genap. Semua fungsi tersebut diakses melalui menu interaktif dalam main, yang berjalan di dalam loop. Pengguna dapat memilih untuk menambah nama, menghapus nama, melihat seluruh isi list, menghitung nama berhuruf genap, atau keluar dari program. Secara keseluruhan, kode ini menyajikan implementasi yang sederhana namun fungsional untuk manipulasi data menggunakan struktur linked list dasar.

3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.
```

===== Program menampilkan menu =====
Masukkan sebuah nama 
input nama .

hasil output
![alt text](image/output1.png)

```

4. Penjelasan Lanjutan (Analisis Output)
Program tersebut dengan menampilkan menu yang berisi beberapa pilihan operasi pada struktur data linked list—mulai dari memasukkan nama, menghapus nama, menampilkan isi list, hingga menghitung jumlah nama dengan panjang huruf genap. Ketika pengguna pertama kali memilih operasi insert, program meminta input sebuah nama dan memasukkannya sebagai node baru di bagian akhir list. Nama pertama yang dimasukkan adalah “Agung”, sehingga ia menjadi satu-satunya node di dalam list pada tahap awal. Saat pengguna mengulangi operasi yang sama dua kali berikutnya dan memasukkan “Rizal” lalu “Rio”, program kembali menambahkan masing-masing nama itu ke bagian paling akhir sehingga list kini berisi tiga elemen secara berurutan: Agung, Rizal, dan Rio.

Ketika pengguna memilih menu view, program menelusuri seluruh node dari awal hingga akhir dan menampilkan isi list. Pada tahap tersebut, output yang muncul adalah “Agung Rizal Rio”, yang menunjukkan bahwa penyisipan telah berlangsung konsisten dan urutannya benar. Setelah itu, pengguna memilih menu delete dan memasukkan nama “Rio” sebagai target penghapusan. Program mencari node yang namanya tepat sama dengan input tersebut dan menghapus node yang ditemukan, menyebabkan list kini hanya berisi “Agung” dan “Rizal”. Ketika view dipanggil kembali, program menampilkan dua nama tersebut, menegaskan bahwa operasi delete berhasil dan struktur list sudah diperbarui dengan benar.

5. Kesimpulan

Berdasarkan implementasi dan pengujian kode di atas, dapat disimpulkan bahwa:
Program ini merupakan implementasi sederhana dari Singly Linked List yang digunakan untuk menyimpan dan memanipulasi data berupa nama mahasiswa. Struktur data ini tersusun dari node–node yang saling terhubung melalui pointer, dimulai dari satu pointer utama yaitu head. Program menyediakan empat operasi utama: menambah nama di akhir list, menghapus nama pertama yang cocok, menampilkan seluruh isi list, dan menghitung jumlah nama dengan panjang huruf genap. Setiap operasi berjalan melalui proses traversal list, sehingga semua fungsi bekerja secara bertahap dari node pertama hingga node terakhir.

Kelebihan program ini adalah kesederhanaannya—struktur code mudah dipahami dan setiap fungsi menjalankan tugasnya secara jelas tanpa kompleksitas berlebih. Selain itu, seluruh proses manipulasi data dilakukan secara langsung melalui pointer, sehingga mencerminkan konsep dasar linked list dengan baik. Meski demikian, beberapa operasi seperti insert di akhir dan delete memerlukan traversal penuh sehingga memiliki kompleksitas O(n). Secara keseluruhan, program ini berhasil menampilkan implementasi yang fungsional, konsisten, dan sesuai dengan karakteristik dasar struktur data linked list.