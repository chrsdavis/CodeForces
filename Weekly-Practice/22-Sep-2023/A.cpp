#include <vector>
#include <algorithm>
#include <ios>
#include <iostream>
#include <set>

using namespace std;

using ull = unsigned long long;

int solve(const vector<ull>& v) {
    set<ull> s(v.begin(), v.end());

    int count = 0;
    ull n = v.size();
    for(ull i = n; i > 0; i--) {
        cout << s.size() << "\n";
        auto it = s.find(i);
        if(it != s.end()) {
            s.erase(it);
        } else {
            count++;
            if(s.empty()) return -1;

            auto max_it = prev(s.end());
            if(*max_it < (i << 1) + 1) {
                return -1;
            }
            s.erase(max_it);
        }
    }
    return count;
}

// fails for 3 2 3, b/c of duplicate 3

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