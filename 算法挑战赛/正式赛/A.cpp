#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 3, MOD = 425;

int t;

void mul(int c[][N], int a[][N], int b[][N])
{
    int temp[N][N] = {0};

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % MOD;
    
    memcpy(c, temp, sizeof temp);
}
void solve()
{
    cin >> t;

    t /= 60;

    int f[N][N] = {1, 1, 1};
    int a[N][N] = {
        {0, 0, 1},
        {1, 0, 1},
        {0, 1, 1}
    };

    if (!t) cout << 0 << endl;
    else if (t == 1 || t == 2 || t == 3) cout << 1 << endl;
    else
    {
        t -= 3;
        while (t)
        {
            if (t & 1) mul(f, f, a);
            mul(a, a, a);
            t >>= 1;
        }
        cout << f[0][2] << endl;
    }

    return ;
}
int main()
{
    solve();

    return 0;
}