#include <iostream>
using namespace std;
const int MAX = 5;
string stackBuku[MAX];
int topIdx = -1;
bool isEmpty();
bool isFull();
void tambahBuku(string judul);
void ambilBuku();
void lihatBukuTeratas();
void tampilkanTumpukan();
int main() {
    int pilih;
    string judul;
    do {
        cout << "\n=== SISTEM TUMPUKAN BUKU PERPUSTAKAAN ===\n";
        cout << "1. Tambah Buku ke Tumpukan (Push)\n";
        cout << "2. Ambil Buku dari Tumpukan (Pop)\n";
        cout << "3. Lihat Buku Teratas (Peek)\n";
        cout << "4. Tampilkan Semua Buku di Tumpukan\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();
        if (pilih == 1) {
            cout << "Masukkan judul buku yang dikembalikan: ";
            getline(cin, judul);
            tambahBuku(judul);
        }
        else if (pilih == 2) {
            ambilBuku();
        }
        else if (pilih == 3) {
            lihatBukuTeratas();
        }
        else if (pilih == 4) {
            tampilkanTumpukan();
        }
    } while (pilih != 5);
    return 0;
}
bool isEmpty() {
    return topIdx == -1;
}
bool isFull() {
    return topIdx == MAX - 1;
}
void tambahBuku(string judul) {
    if (isFull()) {
        cout << "Rak sudah penuh! Tidak bisa menambah buku lagi.\n";
        return;
    }
    stackBuku[++topIdx] = judul;
    cout << "Buku \"" << judul << "\" berhasil ditambahkan ke rak.\n";
}
void ambilBuku() {
    if (isEmpty()) {
        cout << "Rak kosong! Tidak ada buku yang bisa diambil.\n";
        return;
    }
    cout << "Buku \"" << stackBuku[topIdx--] << "\" telah diambil dari rak.\n";
}
void lihatBukuTeratas() {
    if (isEmpty()) {
        cout << "Rak kosong, belum ada buku yang ditumpuk.\n";
        return;
    }
    cout << "Buku teratas di rak: \"" << stackBuku[topIdx] << "\"\n";
}
void tampilkanTumpukan() {
    if (isEmpty()) {
        cout << "Rak kosong!\n";
        return;
    }
    cout << "Tumpukan buku di rak (atas ke bawah): ";
    for (int i = topIdx; i >= 0; --i) {
        cout << stackBuku[i]<<" ";
    }
    cout << endl;
}
