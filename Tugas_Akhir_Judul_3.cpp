#include <iostream>
using namespace std;
int main() {
    int SIZE;
    string book [1005];
    string target;
    int counter = 0;
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
    if (counter > 0) {
        cout << "Buku " << target << " ditemukan sebanyak " << counter << " kali di dalam rak" << endl;
    } else {
        cout << "Buku " << target << " tidak ditemukan." << endl;
    }
    return 0;
}

