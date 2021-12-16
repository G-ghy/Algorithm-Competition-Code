#include <iostream>

using namespace std;

int main()
{
    int res = 0;
    int f, h, t;
    int x;
    
    cin >> x;
    f = x / 160; // 初始发数
    res += f;
    h = f / 10 * 3; // 初始星辉数
    t = f % 10; // 每10发3个星辉，不够10发的发数

    while (h / 5)
    {
        t += h / 5;
        res += h / 5;
        h %= 5;
        h += t / 10 * 3;
        t %= 10;
    }

    cout << res << endl;

    return 0;
}