#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    string str;
    while(t--) {
        unsigned long long sum = 0;
        char chr;
        for(int r = 0; r < 10; r++) {
            for(int c = 0; c < 10; c++) {
                cin >> chr;
                if(chr == '.') continue;

                if(r <= 5) {
                    sum += min(r + 1, min(10 - c, c + 1));
                }else {
                    sum += min(10 - r, min(10 - c, c + 1));
                }
            }
        }
        cout << sum << "\n";
    }
}