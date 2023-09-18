#include <string>
#include <iostream>

using namespace std;

inline bool eq(const string& x, const string& y, const string& z, char op) {
    if(op == '+')
        return stoull(x) + stoull(y) == stoull(z);
    else
        return stoull(x) * stoull(y) == stoull(z);
}

int main() {
    string x,y,z;
    char op, eqls;
    cin >> x >> op >> y >> eqls >> z;

    for(int i = 1; i < x.size(); i++) { // x and y swapped
        string x1 = x.substr(0, i);
        string x2 = x.substr(i);
        for(int j = 1; j < y.size(); j++) {
            string y1 = y.substr(0, j);
            string y2 = y.substr(j);
            if(eq(y1 + x2, x1 + y2, z, op)) {
                cout << y1 + x2 + " " << op << " " << x1 + y2 << " = " << z << "\n";
                return 0;
            }
        }   

        for(int j = 1; j < z.size(); j++) { // x and z swapped
            string z1 = z.substr(0, j);
            string z2 = z.substr(j);
            if(eq(z1 + x2, y, x1 + z2, op)) {
                cout << z1 + x2 + " " << op << " " << y << " = " << x1 + z2 << "\n";
                return 0;
            }
        }
    }


    for(int i = 1; i < y.size(); i++) { // y and z swapped
        string y1 = y.substr(0, i);
        string y2 = y.substr(i);
        for(int j = 1; j < z.size(); j++) {
            string z1 = z.substr(0, j);
            string z2 = z.substr(j);
            if(eq(x, z1 + y2, y1 + z2, op)) {
                cout << x + " " << op << " " << z1 + y2 << " = " << y1 + z2 << "\n";
                return 0;
            }
        }
    }

    return 0;
    

}