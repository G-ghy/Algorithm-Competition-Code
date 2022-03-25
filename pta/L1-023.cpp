#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    string str;
    cin >> str;

    int g, p, l, t;
    g = p = l = t = 0;
    for (char c : str)
        if (c == 'g' || c == 'G') ++g;
        else if (c == 'p' || c == 'P') ++p;
        else if (c == 'l' || c == 'L') ++l;
        else if (c == 't' || c == 'T') ++t;
    
    while (g | p | l | t) {
        if (g) {
            cout << 'G';
            --g;
        }
        if (p) {
            cout << 'P';
            --p;
        }
        if (l) {
            cout << 'L';
            --l;
        }
        if (t) {
            cout << 'T';
            --t;
        }
    }
}
int main() {
    solve();
    return 0;
}