#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Masukkan jumlah barang: ";
    cin >> n;
    string item[100];
    int harga[100];
    for (int i = 0; i < n; i++){
        cout << "Nama barang: ";
        cin >> item[i];
        cout << "Harga: ";
        cin >> harga[i];
    }
    for (int i = 1; i < n; i++){
        int tempHarga = harga[i];
        string tempItem = item[i];
        int j = i - 1;
        while (j >= 0 && harga[j] < tempHarga){
            harga[j + 1] = harga[j];
            item[j + 1] = item[j];
            j--;
        }
        harga[j + 1] = tempHarga;
        item[j + 1] = tempItem;
    }
    cout << "Daftar Harga Setelah Diskon\n";
    for (int i = 0; i < n; i++){
        double diskon = 0.0;
        if (i == 0)
            diskon = 0.30;
        else if (i == 1)
            diskon = 0.20;
        else if (i == 2)
            diskon = 0.10;
        double hargaAkhir = harga[i] * (1 - diskon);
        cout << item[i] << " - Rp" << harga[i];
        if (diskon > 0){
            cout << " > Rp" << hargaAkhir
                 << " (Diskon " << diskon * 100 << "%)";
        }
        cout << endl;
    }
    return 0;
}
