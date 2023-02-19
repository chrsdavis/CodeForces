#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

int encode(char c) {
    if (isalpha(c))
        return c - 'A';
    if (isdigit(c))
        return c - 48 + 25;
    else
        return 36;
}

char decode(int i) {
    if (i < 26)
        return static_cast<char>(i + 'A');
    if (i < 36)
        return static_cast<char>(i - 26 + '0');
    else
        return ' ';

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j];

    string ciphertext;
    cin.ignore();
    getline(cin, ciphertext);

    int r = (n - (ciphertext.size() % n)) % n;
    vector<int> encrypted;
    encrypted.reserve(ciphertext.size());
    for(char c: ciphertext) {
        encrypted.push_back(encode(c));
    }

    for(int i = 0; i < r; i++) {
        encrypted.push_back(36);
    }

    // for(int i: encrypted) cout << i << " ";
    // cout << "\n";


    int a[n];
    for(int i = 0; i < encrypted.size(); i += n) {
        for(int j = 0; j < n; j++) {
            a[j] = 0;
            for(int k = 0; k < n; k++)
                a[j] += encrypted[i + k] * m[j][k];
                //cout << encrypted[i + k] << " * " << m[j][k] << " + ";
        }

        for(int j = 0; j < n; j++) {
            // cout << a[j] % 37  << "\n";
            encrypted[i + j] = a[j] % 37;
        }
    }

    for(int c: encrypted)
        cout << decode(c);
    cout << "\n";

    // FPLSFA4SUK2W9K3
    // FPLSFA4SUK2W9K3

}
