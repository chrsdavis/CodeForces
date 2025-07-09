#include <vector>
#include <cstdint>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <iterator>

using ull = unsigned long long;
using ll = long long;

using namespace std;

static bool is_derangement(std::vector<int>& arr) {
    while (true) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int j = 0;
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i] != arr[i]) {
                arr[j++] = arr[i];
            }
        }
        if (j == sorted.size()) break;  // found solution
        arr.erase(arr.begin() + j, arr.end());
    }
    return !arr.empty();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i]; 
        if (is_derangement(arr)) {
            cout << "YES\n";
            cout << arr.size() << "\n";
            for (int i: arr) cout << i << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}