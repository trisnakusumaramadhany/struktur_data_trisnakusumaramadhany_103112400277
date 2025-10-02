#include <iostream>

using namespace std;

int main(){

    string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
    string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas","lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};

    int n;
    cout << "masukkan angka : ";
    cin >> n;

    if (n < 10){
        cout << satuan[n] << endl;
    } else if (n < 20){
        cout << belasan[n - 10] << endl;
    } else if (n < 100){
        cout << satuan[n / 10] << " puluh ";
        if (n % 10 != 0) cout << " " << satuan[n % 10];
        cout << endl;
    } else if (n == 100){
        cout << " seratus " << endl;
    } else {
        cout << "eror!" << endl;
    }
    return 0;
}