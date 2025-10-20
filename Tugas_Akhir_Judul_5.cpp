#include <iostream>
#include <iomanip>
using namespace std;
struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};
Node *insertNode(Node *root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    return root;
}
void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
int findMin(Node *root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->key;
}
int findMax(Node *root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->key;
}
int countNodes(Node *root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
long long sumNodes(Node *root) {
    if (!root) return 0;
    return root->key + sumNodes(root->left) + sumNodes(root->right);
}
int main() {
    Node *root = nullptr;
    int pilih, nilai;
    do {
        cout << "\n=== SISTEM MANAJEMEN NILAI MAHASISWA ===\n";
        cout << "1. Tambah Nilai\n2. Tampilkan Urutan Nilai\n";
        cout << "3. Nilai Tertinggi & Terendah\n4. Total & Rata-rata Nilai\n5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        if (pilih == 1) {
            cout << "Masukkan nilai mahasiswa: ";
            cin >> nilai;
            root = insertNode(root, nilai);
            cout << "Nilai " << nilai << " berhasil disimpan.\n";
        } 
        else if (pilih == 2) {
            cout << "Daftar nilai mahasiswa: ";
            inorder(root);
            cout << "\n";
        } 
        else if (pilih == 3) {
            cout << "Nilai terendah : " << findMin(root) << endl;
            cout << "Nilai tertinggi: " << findMax(root) << endl;
        } 
        else if (pilih == 4) {
            int total = sumNodes(root);
            int jumlah = countNodes(root);
            double rata = (jumlah > 0) ? (double)total / jumlah : 0;
            cout << "Jumlah mahasiswa: " << jumlah << endl;
            cout << "Total nilai     : " << total << endl;
            cout << "Rata-rata nilai : " << rata << endl;
        } 
        else if (pilih == 5) {
            cout << "Program selesai.\n";
        } 
        else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);
    return 0;
}
