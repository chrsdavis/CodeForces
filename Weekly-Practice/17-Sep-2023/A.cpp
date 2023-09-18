// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    int count = 0;
    for(int i = 5; i > 0 && x > 0; i--) {
        int t = x / i;
        x -= t * i;
        count += t;
    }
    cout << count;
    return 0;
}