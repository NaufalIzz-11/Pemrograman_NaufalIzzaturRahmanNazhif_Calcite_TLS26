#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N) dan nilai K awal: ";
    cin >> N >> K;

    bool eliminated[1000];
    for (int i = 0; i < N; i++) {
        eliminated[i] = false;
    }

    int pos = 0;
    int remaining = N;

    cout << "\n--- Proses Eliminasi ---" << endl;

    while (remaining > 1) {
        int count = 0;
        int idx = pos;

        while (count < K) {
            if (!eliminated[idx]) {
                count++;
            }
            if (count == K) {
                break;
            }
            idx = (idx + 1) % N;
        }

        cout << "Astronot " << (idx + 1) << " dieliminasi" << endl;
        eliminated[idx] = true;

        if ((idx + 1) % 2 == 0) { 
            K = K + 2;
        } else {
            K = K - 1;
        }
        if (K < 2) {
            K = 2;
        }

        int next = (idx + 1) % N;
        while (eliminated[next]) {
            next = (next + 1) % N;
        }
        pos = next;
        remaining--;
    }

    for (int i = 0; i < N; i++) {
        if (!eliminated[i]) {
            cout << "\nAstronot terakhir yang bertahan: " << (i + 1) << endl;
        }
    }

    return 0;
}