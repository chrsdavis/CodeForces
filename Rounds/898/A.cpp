#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    string str;
    while(t--) {
        cin >> str;
        if(str == "bca" || str == "cab")
            cout << "NO\n";
        else 
            cout << "YES\n";
    }
}