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
        int n, w;
        cin >> n >> w;
        vector<ull> v(n);
        ull mi = INT_MAX, ma = 0;
        for(ull& i: v) {
            cin >> i;
            mi = min(i, mi);
            ma = max(i, ma);
        }

        int l = mi;
        int r = (w / n) + ma;
        int max_height = 0;

        while(l <= r) {
            int h = (l + r) / 2;
            ull w1 = 0;
            for(ull i: v) {
                w1 += (i <= h) ? h - i : 0;
                if(w1 > w) {
                    break;
                }
            }

    
            if(w1 > w) r = h - 1;
            else {
                l = h + 1;
                max_height = max(max_height, h);
            }

        }
        cout << max_height << "\n";

    }
}