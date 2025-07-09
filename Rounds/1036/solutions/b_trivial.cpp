// Solution from  dani_i

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <functional>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <utility>
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = a[0] + a[1];

    if (n == 2) {
        ans = min(ans, a[0] + min(a[0], a[1]));
    }

    if (n > 2) {
        ans = min(ans, a[0] + min(a[0], a[1] + a[2]));
    }

    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}