#include <iostream>
using namespace std;

int main() {
    char text[100];
    cout << "Masukkan teks (Dalam kapital): ";
    cin >> text;
    cout << text[0];
    
    for (int i = 1; text[i] != '\0'; i++) {
        int convert = text[i] - 65;
        int shift = text[i-1] - 65;

        char result = 'A' + (convert + shift) % 26 ;
        cout << result;
    }
    return 0;
}