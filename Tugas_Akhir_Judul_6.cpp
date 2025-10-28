#include <iostream>
#include <string>
using namespace std;
const int SIZE = 10;
struct Node {
    int id;
    string nama;
    int harga;
    Node* next;
};
void initTable(Node *table[]){
    for (int i = 0; i < SIZE; i++){
        table[i] = nullptr;
    }
}
int hashFunction(int key) { return key % SIZE; }
void insert(Node* table[], int id, string nama, int harga) {
    int index = hashFunction(id);
    Node *cur = table[index];
     while (cur != nullptr) {
        if (cur->id == id) { 
            cur->nama = nama;
            cur->harga = harga;
            cout << "Barang ID " << id << " diperbarui!\n";
            return;
        }
        cur = cur->next;
    }
    table[index] = new Node{id, nama, harga, table[index]};
    cout << "Barang Ditambahkan"<<endl;
}
Node* search(Node* table[], int id) {
    int index = hashFunction(id);
    Node *cur = table[index];
    while (cur != nullptr) {
        if (cur->id == id) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}
void display(Node *table[]) {
    cout << "\nIsi Rak:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        Node *tmp = table[i];
        while (tmp != nullptr) {
            cout << "(ID:" << tmp->id << ", " << tmp->nama << ", Rp" << tmp->harga << ") -> ";
            tmp = tmp->next;
        }
        cout << "NULL\n";
    }
}
void removeKey(Node *table[], int id) {
    int index = hashFunction(id);
    Node *cur = table[index];
    Node *prev = nullptr;
    while (cur != nullptr) {
        if (cur->id == id) {
            if (prev == nullptr) {
                table[index] = cur->next;
            }
            else {
                prev->next = cur->next;
            }
            delete cur;
            cout << "Barang ID " << id << " dihapus!\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "Barang dengan ID " << id << " tidak ditemukan!\n";
}
int main() {
    Node* table[SIZE] = {nullptr};
    int menu;
    do {
        cout << "\n====================================\n";
        cout << "1. Tambah\n2. Tampilkan\n3. Cari\n4. Hapus\n0. Keluar\n";
        cout<<"Pilih menu: ";
        cin >> menu;
        if (menu == 1) {
            cout << "\n--- Panduan ID Umum ---\n"
                 << "101 - Alat Tulis\n"
                 << "111 - Sembako\n"
                 << "121 - Jajanan\n"
                 << "131 - Obat-obatan\n";
            int id, harga;
            string nama;
            cout << "Masukkan ID Barang: "; cin >> id;
            cout << "Masukkan Nama Barang: "; cin.ignore(); getline(cin, nama);
            cout << "Masukkan Harga: "; cin >> harga;
            insert(table, id, nama, harga);
        }
        else if (menu == 2) display(table);
        else if (menu == 3) {
            int id;
            cout << "Masukkan ID: "; 
            cin >> id;
            Node* n = search(table, id);
            if (n != nullptr) cout << "Ditemukan! " << n->nama << " (Rp" << n->harga << ")\n";
            else cout << "Barang tidak ditemukan!\n";
        }
        else if (menu == 4) {
            int id; cout << "Masukkan ID: "; cin >> id;
            removeKey(table, id);
        }
    } while (menu != 0);
    cout << "\nTerima kasih telah menggunakan sistem toko!\n";
    return 0;
}
