#include <vector>
#include <algorithm>
#include <ios>
#include <iostream>
#include <set>

using namespace std;

using ull = unsigned long long;

void backtrack(vector<ull>& ans, ull b) {
    ull a = ans.back();
    if(a == b) return;
    if(10 * a + 1 <= b) {
        ans.push_back(10 * a + 1);
        backtrack(ans, b);
        if(ans.back() == b) return;
        ans.pop_back();
    }

    if(2 * a <= b) {
        ans.push_back(2 * a);
        backtrack(ans, b);
        if(ans.back() == b) return;
        ans.pop_back();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull a, b;
    cin >> a >> b;
    if(a == b) {
        cout << "YES\n1\n" << a << "\n";
    }

    vector<ull> ans = { a };
    backtrack(ans, b);
    if(ans.size() != 1) {
        cout << "YES\n" << ans.size() << "\n";
        for(int i: ans) cout << i << " ";
        cout << "\n";
    }else {
        cout << "NO\n";
    }
}