/**
 * 最开始想的使用dfs做，但是改了半天，dfs无效搜索太多，怎么弄都是超时
 * 后来想着之所以使用dfs，是因为左上角的值不能确定，观察发现n最大也不过1000
 * 大不了就直接枚举左上角的值，然后每次选择剩余元素中的最大值，判断是否可以构造出答案即可
 * 这样的思路是没有问题的，但是它还是超时
 * 
 * 问题大概率就是在memcpy那里，但是每次操作times的值一定会被更改，只要我想恢复就只能进行拷贝，
 * 后来我想能不能更改判断逻辑，想了一下每次不是memcpy就是memset，怎么弄都是超时
 * 
 * 我看了一下ac的代码，相比于memcpy的恢复方式，他们采用了容器的赋值解决了超时的问题
 * 这是因为，数据的个数最多才2000个，但是数据的范围到了1e6，容器赋值是1e3级别的操作，memcpy是1e6级别的操作
 * 所以可以解决超时
 * 回过头来想这里的实质是在维护一个有序序列，同时从中删除一些数据后仍要求保持有序
 * set和multiset均是具有这种性质的容器
 * 而题目的数据可能存在重复，所以采用multiple即可，只需要把原代码中的标记操作改为删除操作
 * 注：感觉很奇妙，大多时候都是一些标记操作就可以解决的问题我总是采用真的模拟去做，写的乱七八糟还不对，没想到现在确是把标记改为真正删除
 * 由于底层采用的是红黑树，删除和维护有序的复杂度都很绝
 */
// #include <cstdio>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// const int N = 1010, SIZE = 1e6 + 10;

// int n;
// int a[2 * N], times[SIZE], t[SIZE];
// int res[N], cnt;

// bool judge(int u)
// {
//     int sum;
//     --times[a[u]];

//     // 选择存在的最大值为初始sum
//     for (int i = 2 * n; i; --i)
//         if (times[a[i]])
//         {
//             sum = max(a[u], a[i]);
//             --times[a[i]];
//             res[cnt++] = a[i];
//             break;
//         }
    
//     for (int i = 2 * n; i; --i)
//     {
//         if (!times[a[i]]) continue;
//         --times[a[i]];
//         if (!times[sum - a[i]])
//         {
//             ++times[a[i]];
//             continue;
//         }
//         --times[sum - a[i]];
//         res[cnt++] = a[i];
//         sum = max(sum - a[i], a[i]);
//     }

//     return cnt == n;
// }
// int main()
// {
//     freopen("in.txt", "r", stdin);
//     int T;
//     scanf("%d", &T);
//     while (T--)
//     {
//         memset(times, 0, sizeof times);
//         scanf("%d", &n);
//         for (int i = 1; i <= 2 * n; ++i)
//         {
//             scanf("%d", &a[i]);
//             ++times[a[i]];
//         }

//         sort(a + 1, a + 2 * n + 1);

//         int pos = -1;
//         memcpy(t, times, sizeof times);
//         // n是1e3，每次memcpy是1e6，1e9的复杂度导致了超时
//         for (int i = 1; i <= 2 * n; ++i)
//         {
//             cnt = 0;
//             memcpy(times, t, sizeof times);
//             if (judge(i))
//             {
//                 pos = i;
//                 break;
//             }
//         }

//         if (pos == -1) printf("NO\n");
//         else
//         {
//             printf("YES\n");
//             int sum = a[pos] + res[0];
//             printf("%d\n", sum);
//             for (int i = 0; i < cnt; ++i)
//             {
//                 printf("%d %d\n", sum - res[i], res[i]);
//                 sum = max(sum - res[i], res[i]);
//             }
//         }
//     }

//     fclose(stdin);
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
using PII = pair<int, int>;

const int N = 2020;

int n;
int a[N];
multiset<int> s, s_t;
vector<PII> res;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        s.clear();

        cin >> n;
        n <<= 1;
        for (int i = 1; i <= n; ++i) cin >> a[i]; // 还是要存储一下的，不能直接放到multiset中，因为后续我们需要枚举左上角的值，set是不能顺序索引的
        sort(a + 1, a + n + 1);
        for (int i = 1; i < n; ++i) s.insert(a[i]); // 注意这里并没有把最大值放进去
        
        int maxn;
        bool flag;
        for (int i = 1; i < n; ++i)
        {
            flag = true;
            res.clear();
            s_t.clear();
            s_t = s;
            int nextSum = a[n];
            s_t.erase(s_t.find(a[i])); // 这样会把所有等于a[i]的元素删除，想要仅删除一个需要使用find()提供迭代器 s_t.erase(a[i]);
            res.push_back({a[i], a[n]});

            while (s_t.size())
            {
                int maxr = *(s_t.rbegin());
                int maxl = nextSum - maxr;
                nextSum = maxr;
                s_t.erase(s_t.find(maxr));

                if (!(s_t.count(maxl)))
                {
                    flag = false;
                    break;
                }
                s_t.erase(s_t.find(maxl));
                res.push_back({maxl, maxr});
            }
            
            if (flag) break;
        }

        if (!flag) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << (res[0].first + res[0].second) << endl;
            for (PII pii : res)
                cout << pii.first << ' ' << pii.second << endl;
        }
    }
}