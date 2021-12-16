/**
 * 如果仅有2个串，答案是很好构造的
 * 仅有2个串，问题可以转化为了在第2个串中是否存在一个位置，除这个位置以外的位置，第1个串与第2个串对应位置最多只有一位不同
 * 如果存在，则一个合法的答案为上述选定位置的字符选择第2个串，其余位置选择第1个串
 * 
 * 暴力想法是，对于每一位去枚举现有字符串中的值，然后与每一个现有字符串逐一验证
 * 一共n个字符串，每个字符串m位，最坏情况总共需要枚举n^m次，
 * abc
 * bcd
 * cde
 * 第1位枚举a，b，c
 * 第2位枚举b，c，d
 * 第3位枚举c，d，e
 * 共3*3*3=27种
 * 验证过程是O(nm)的
 * 10^10一定会超时的
 * 
 * 暴力做法还可以选定第1个串作为基准串，因为答案要满足符合所有串的要求，那么必要要满足第一个串的要求
 * 因此对于第1个串的每一位，从a枚举到z，期间判断是否有解
 * 这样的复杂度是n^3
 * 
 * ！！！！这这这，居然是n^3，上面的暴力可是n^m，这是我没想到的
 * 暴力都想不出来也是没谁了
 * 我都没往简单了想，依照着2个串的处理思路，总是在想什么动态规划之类的
 */
#include <iostream>
#include <cstring>

using namespace std;

const int N = 15;

int n, m;
char s[N][N];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        bool flag = false;
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            for (int i = 0; i < m; ++i)
            {
                char t = s[0][i];
                s[0][i] = ch;
                int cnt = 0;
                for (int j = 1; j < n; ++j)
                {
                    cnt = 0;
                    for (int k = 0; k < m; ++k)
                    {
                        if (s[0][k] != s[j][k]) ++cnt;
                        if (cnt > 1) break;
                    }
                    if (cnt > 1) break;
                }
                if (cnt <= 1)
                {
                    flag = true;
                    break;
                }
                s[0][i] = t;
            }
            if (flag) break;
        }
        if (flag) printf("%s\n", s[0]);
        else printf("-1\n");
    }
}