#include <iostream>
using namespace std;
int main() {
    int SIZE;
    string book [1005];
    string target;
    int counter = 0;
    cout << "===============================" << endl;
    cout << "   PROGRAM PENCARIAN BUKU" << endl;
    cout << "===============================" << endl;
    cout<<"Masukan jumlah buku dalam rak: ";
    cin>>SIZE;
    cout<<"Masukkan  jenis tiap Buku dalam rak: "<<endl;
    for (int i = 0; i < SIZE; i++) {
        cout<<"Buku ";
        cin >>book[i];
    }
    cout << "Masukkan jenis buku yang ingin dicari: Buku ";
    cin >> target;
    for (int i = 0; i < SIZE; i++) {
        if (book[i] == target) {
            counter++;
        }
    }
    cout << "\n=== HASIL PENCARIAN ===" << endl;
    if (counter > 0) {
        cout << "Jenis buku  : " << target << endl;
        cout << "Jumlah      : " << counter << " buku" << endl;
        cout << "Persentase  : " << (counter * 100.0 / SIZE) << "% dari total rak" << endl;
        cout << "Status      : Ditemukan" << endl;
    } else {
        cout << "Jenis buku  : " << target << endl;
        cout << "Jumlah      : 0 buku" << endl;
        cout << "Status      : Tidak ditemukan" << endl;
    }
    cout << "=======================" << endl;
    return 0;
}