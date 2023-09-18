#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string str, t;
    unordered_map<string, int> hm;
    for(int i = 0; i < 2*n - 2; i++) {
        cin >> str;
        hm[str]++;
        t = str;
        reverse(str.begin(), str.end());
        if(t != str) hm[str]++;
    }
    for(auto& p: hm) {
        // cout << p.first << " " << p.second << "\n";
        if (p.second % 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}