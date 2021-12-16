/**
 * 设k满足，2^{k+1} - 2 >= t
 * 则答案公式为：[t - (2^k - 2)] * k + sum(i * 2^i)(1 <= i <= k - 1)
 */
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int k;
    for (int i = 1; ; ++i)
        if ((1 << (i + 1)) - 2 >= t)
        {
            k = i;
            break;
        }
    
    int res = 0;
    res += (t - ((1 << k) - 2)) * k;
    for (int i = 1; i <= k - 1; ++i)
        res += i * (1 << i);

    cout << res << endl;

    return 0;
}