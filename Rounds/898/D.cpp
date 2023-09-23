#include <iostream>
#include <string>
#include <vector>
#include <ios>

using namespace std;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        char c;
        int n, k;
        string str;
        cin >> n >> k >> str;
        ull count = 0;

        for(int i = 0; i < n; i++) {
            if(str[i] == 'B') {
                count++;
                i += k - 1;
            }
        }
        cout << count << "\n";
    }
}
