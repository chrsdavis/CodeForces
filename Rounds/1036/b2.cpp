#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    const ll INF = LLONG_MAX / 4;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), m(n), D(n+1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[i] = (i == 0 ? a[i] : min(m[i-1], a[i]));
        }
        D[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            D[i] = D[i+1] + m[i];
        }
        ll S = D[0], best = 0;
        for (int i = 0; i + 1 < n; i++) {
            ll prev = (i == 0 ? INF : m[i-1]);
            ll inc = min(prev, a[i] + a[i+1]) - m[i];
            ll dec = D[i+1];
            best = max(best, dec - inc);
        }
        cout << S - best << "\n";
    }
    return 0;
}
