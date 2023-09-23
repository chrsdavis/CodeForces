#include <vector>
#include <algorithm>
#include <ios>
#include <iostream>
#include <set>

using namespace std;

using ull = unsigned long long;

int solve(const vector<ull>& v) {
    ull n = v.size();
    set<ull> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    vector<ull> vc;

    for(int i: v) {
        auto it = s.find(i);
        if(it != s.end()) {
            s.erase(it);
        }else{
            vc.push_back(i);
        }
    }

    sort(vc.rbegin(), vc.rend());
    for(int i: vc) {
        auto max_it = prev(s.end());
        if(i < *max_it * 2 + 1) return -1;
        s.erase(max_it);
    }
    return vc.size();
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ull> v(n, 0);
        for(ull& i: v) cin >> i;
        cout << solve(v) << "\n";
    }
}