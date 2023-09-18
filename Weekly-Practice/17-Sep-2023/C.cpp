#include <vector>
#include <iostream>

using namespace std;

void solve(int n, int len) {
    vector<string> vs(n);
    for(int i = 0; i < n; i++) {
        cin >> vs[i];
    }
    int min_dist = INT_MAX;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int dist = 0;
            for(int c = 0; c < len; c++) {
                dist += abs(vs[i][c] - vs[j][c]);
            }
            min_dist = min(dist, min_dist);
        }
    }
    cout << min_dist << "\n";
}

int main () {
    int t;
    cin >> t;
    while(t--) {
        int n, len;
        cin >> n >> len;
        solve(n, len);
    }
}