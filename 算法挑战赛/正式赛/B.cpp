// 找到序列中的次小值

#include <iostream>

using namespace std;

constexpr int INF = 2147483647;

void solve()
{
    int n;
    int min1 = INF, min2 = INF;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (a < min1) min2 = min1, min1 = a;
        else if (a < min2) min2 = a;
    }

    cout << min2 << endl;
}
int main()
{
    solve();

    return 0;
}