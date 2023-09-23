#include <vector>
#include <algorithm>
#include <ios>
#include <iostream>
#include <set>

using namespace std;

using ull = unsigned long long;

// 1 5 2 1 1 1 2 5 7 2
// [1,4] [2, 3] [5, 2] [7, 1]
// 4 3 2 1

int main() {
    std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    int max_count = 0;

    if(n > m) {
        cout << max_count << "\n";
        return 0;
    }
    vector<int> type(101, 0);
    int t;
    for(int i = 0; i < m; i++) {
        cin >> t;

        type[t]++;
    }


    sort(type.rbegin(), type.rend());

    int ub = type[0];

    for(int i = ub; i > 0; i--) {

        int people = 0;
        for(int total: type) {
            if(total < i || people >= n) break;
            people += total / i;
        }
        if(people >= n) {
            max_count = i;
            break;
        }
    }

    cout << max_count << "\n";

    
}