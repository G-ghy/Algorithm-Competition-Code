// 贪心可做
// 男孩女孩均从小到大排序
// 每个男孩尽可能选择靠前的女孩进行匹配，且当前的女孩是之前男孩匹配女孩之后的位置
// 贪心的证明：可以证明任何一组发生交叉的匹配方式都可以修改为不交叉的匹配方式
// 所有方案包括交叉的方案和不交叉的方案
// 而不交叉的方案又都可以修改为不交叉的方案
// 因此，不交叉方案中的局部最优解即为全局最优解
// 所以考虑不交叉如何更多地匹配，即为上面的策略
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 1e5 + 10;

int n, m;
int a[N], b[N];
int match[N];
bool st[N];
int head[N], e[M], ne[M], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx++;
}
bool find(int x)
{
    for (int i = head[x]; i != -1; i = ne[i]) {
        int p = e[i];

         if (!st[p] && abs(a[x] - b[p]) <= 1) {
             st[p] = true;
             if (!match[p] || find(match[p])) {
                 match[p] = x;
                 return true;
             }
         }
    }
    
    return false;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m;
    for (int i = n + 1; i <= n + m; ++i) cin >> b[i];
    
    memset(head, -1, sizeof head);

    for (int i = 1; i <= n; ++i)
        for (int j = n + 1; j <= n + m; ++j)
            add(i, j);
    
    // 遍历每一个男生，判断其是否可以找到匹配
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        memset(st, false, sizeof st);
        if (find(i)) ++res;
    }
    
    cout << res << endl;
}
