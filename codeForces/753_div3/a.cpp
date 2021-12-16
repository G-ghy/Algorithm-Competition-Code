#include <iostream>
#include <cstring>

using namespace std;

constexpr int N = 60;

char s1[N], s2[N];
int val[N];

void solve() {
    int res = 0;

    scanf("%s", s1);
    scanf("%s", s2);

    for (int i = 0; i < 26; ++i)
        val[s1[i] - 'a'] = i;
    for (int i = 1; i < strlen(s2); ++i)
        res += abs(val[s2[i] - 'a'] - val[s2[i - 1] - 'a']);
    
    printf("%d\n", res);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}