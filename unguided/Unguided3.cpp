#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int n;
    cout << "Masukkan: ";
    cin >> n;
    cout << "Keluaran:" << endl;

    int maxWidth = (n * 2) + 1; 

    for (int i = n; i >= 1; i--) {
        // Buat string sementara untuk baris
        string line = "";

        for (int j = i; j >= 1; j--) {
            line += to_string(j);
        }

        line += "*";

        for (int j = 1; j <= i; j++) {
            line += to_string(j);
        }
        int padding = (maxWidth - line.length()) / 2;
        cout << string(padding, ' ') << line << endl;
    }
    return 0;
}
