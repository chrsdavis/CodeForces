#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& i: v) cin >> i;

    for(int i = n - 1; i > 0; i--) {
        int j = 0;
        // cout << v[i-1] << " " << v[i] << "\t" << gcd(v[i], v[i-1]) << " " << (v[i-1] != 1) << "\n";
        while((gcd(v[i], v[i-1] + j) != 1 && v[i] >= v[i-1]) || v[i-1] == 1) 
            v[i-1]++;
        v[i-1] += j;
    }
    for (int i: v) cout << i << " ";
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}