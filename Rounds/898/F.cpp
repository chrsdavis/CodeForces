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
        ull n, k;
        cin >> n >> k;
        vector<ull> a(n);
        vector<ull> h(n);
        for(ull& i: a) cin >> i;
        for(ull& i: h) cin >> i;

        int sum = 0, count = 0, max_count = 0;
        for(int i = 0; i < n; i++) {

            if(i != 0 && h[i - 1] % h[i] != 0) {
                count = 0; // not divisible
            }

            if(sum + a[i] <= k) {
                sum += a[i];
                count++;
            }else if(sum > 0) {
                sum -= a[i - count];
                sum += a[i];
            }

            max_count = max(max_count, count);
        }
        cout << max_count << "\n";
    }
}
