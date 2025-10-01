#include <iostream>
using namespace std;

int main() {
    double total_pembelian, diskon;
    cout << "Berapa kamu belanja: Rp. ";
    cin >> total_pembelian;

    if (total_pembelian >= 30000) {  // ← pakai { }
        diskon = 0.1 * total_pembelian;
        cout << "Kamu dapat diskon sebesar Rp. " << diskon 
             << " orang kaya lu tong" << endl;
    } else {
        cout << "Belanja kamu kurang dari Rp. 30000, tidak dapat diskon." << endl;
    }

    return 0;
}
