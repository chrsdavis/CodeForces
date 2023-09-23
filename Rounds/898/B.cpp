#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    string str;
    while(t--) {
        cin >> n;
        int num_zero = 0;
        unsigned long long prod = 1;
        int digit, Min = INT_MAX;
        while(n--) {
            cin >> digit;
            Min = min(digit, Min);
            if(digit > 0) prod *= digit;
            else num_zero++;
        }
        if(num_zero == 1) {
            cout << prod << "\n";
        }else if(num_zero > 1) {
            cout << 0 << "\n";
        } else {
            prod /= Min;
            prod *= Min + 1;
            cout << prod << "\n";
        }
    }
}