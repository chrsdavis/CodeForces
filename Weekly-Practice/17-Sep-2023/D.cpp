#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cols;
    while(cin >> cols) {
        string s;
        cin >> s;
        int N = s.size();
        int rows = N / cols;

        string out = s;

        for(int i = 0; i < N; i++) {
            int c = i / rows;
            int r = i % rows;

            out[r * c + c] = s[i];
        }
        cout << out << "\n";
    }
}