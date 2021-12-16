/**
 * 1. 连续序列
 * 2. 平衡 = count(a) = count(b)
 * 3. 非空
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int n;
string s;
int fa[60], fb[60];

int main()
{
    int T;
    cin >> T;
    while (T --)
    {
        memset(fa, 0, sizeof fa);
        memset(fb, 0, sizeof fb);

        cin >> n;
        cin >> s;
        for (int i = 0; i < s.size(); ++ i)
            if (s[i] == 'a') 
            {
                fa[i + 1] = fa[i] + 1;
                fb[i + 1] = fb[i];
            }
            else 
            {
                fa[i + 1] = fa[i];
                fb[i + 1] = fb[i] + 1;
            }
        
        int l = -1, r = -1;
        bool flag = false;
        for (int i = 1; i <= s.size(); ++ i)
        {
            for (int j = i + 1; j <= s.size(); ++ j)
            {
                int a = fa[j] - fa[i - 1], b = fb[j] - fb[i - 1];
                if (a == b)
                {
                    l = i, r = j;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        cout << l << ' ' << r << endl;
    }

    return 0;
}