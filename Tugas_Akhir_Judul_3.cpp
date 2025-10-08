#include <iostream>
using namespace std;
int main() {
    const int SIZE = 10;
    string cars[SIZE];
    string target;
    int count = 0;
    cout << "Masukkan " << SIZE << " mobil ke parkiran: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> cars[i];
    }
    cout << "Masukkan mobil yang ingin dicari: ";
    cin >> target;
    for (int i = 0; i < SIZE; i++) {
        if (cars[i] == target) {
            count++;
        }
    }
    if (count > 0) {
        cout << "Mobil " << target << " ditemukan sebanyak " << count << " kali" << endl;
    } else {
        cout << "Mobil " << target << " tidak ditemukan." << endl;
    }
    return 0;
}

