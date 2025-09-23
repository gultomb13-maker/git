#include <iostream>
using namespace std;
int main() {
    char papan[3][3];
    char posisi = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            papan[i][j] = posisi++;
    char pemain = 'X';
    int langkah = 0;
    while (true) {
        cout << "\nPapan Tic Tac Toe:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << papan[i][j] << " ";
            cout << endl;
        }
        char pilih;
        cout << "Giliran " << pemain << ". Pilih kotak (1-9): ";
        cin >> pilih;
        bool valid = false;
        for (int i = 0; i < 3 && !valid; i++) {
            for (int j = 0; j < 3; j++) {
                if (papan[i][j] == pilih) {
                    papan[i][j] = pemain;
                    valid = true;
                }
            }
        }
        if (!valid) {
            cout << "Kotak tidak valid, coba lagi!\n";
            continue;
        }
        langkah++;
        for (int i = 0; i < 3; i++) {
            if (papan[i][0] == pemain && papan[i][1] == pemain && papan[i][2] == pemain ||
                papan[0][i] == pemain && papan[1][i] == pemain && papan[2][i] == pemain) {
                cout << "Pemain " << pemain << " menang!\n";
                return 0;
            }
        }
        if (papan[0][0] == pemain && papan[1][1] == pemain && papan[2][2] == pemain ||
            papan[0][2] == pemain && papan[1][1] == pemain && papan[2][0] == pemain) {
            cout << "Pemain " << pemain << " menang!\n";
            return 0;
        }
        if (langkah == 9) {
            cout << "Permainan seri!\n";
            return 0;
        }
        if (pemain == 'X') {
            pemain = 'O';
        } else {
            pemain = 'X';
        }
    }
}
