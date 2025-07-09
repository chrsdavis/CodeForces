// Solution from TkachDan

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <complex>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>

using namespace std;

#define int long long


void sol() {
    int n;
    cin >> n;
    vector<int> lst(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }
    int q = lst[0];
    int real_ans = 0;
    for (int i = 0; i < n; i++) {
        q = min(q, lst[i]);
        real_ans += q;
    }
    real_ans = min(real_ans, lst[0] + lst[1]);
    if (n > 2 && lst[0] < lst[1]) {
        real_ans = min(real_ans, lst[0] + lst[0]);
    }
    cout << real_ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(57);
    int t;
    cin >> t;
    for (; t > 0; --t) {
        sol();
    }
}