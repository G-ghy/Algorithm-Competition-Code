/**
 * 首先想到的枚举思路就是枚举每根木棒是放在已有组中还是新开一组，如果仅用这个思路，需要把所有木棒安置好后再检查是不是合法情况，同时还要维护全局最小值
 * 
 * 然后想到了分成的组数一定得能够整除总长度
 * 然后发现指定了组数之后，每组的长度也就确定了
 * 由于此前做过165.小猫爬山一题，如果每组的长度是给定的，那么本题和165就是一样的了
 * 所以去想不妨在搜索之前枚举一下组数，顺便就可以得到每组最终的长度值，之后的做法和165就是完全一样的了
 * 
 * 分类问题中，dfs有两种实现方式，
 * 1. 考虑每个元素处在哪个集合中
 * 2. 考虑每个集合中有哪些元素
 * 此前的问题采用的均是第1种实现方式，但是在本题中如果采用第一种实现方式，很多剪枝是没办法做的
 */
// #include <iostream>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// constexpr int N = 70;

// int n;
// int sum, maxx, a[N];
// int len; // 最终每组长度
// int g[N], gcnt;

// bool dfs(int cnt) {
//     if (cnt == n) {
//         for (int i = 0; i < gcnt; ++i)
//             if (g[i] != len) return false;
//         return true;
//     }
//     // 最优性剪枝，规定每组长度为len，即最多分为sum/len组，如果此时已经超过了规定组数，则直接返回
//     if (gcnt > sum / len) return false;

//     // 考虑加到之前的一组中
//     for (int i = 0; i < gcnt; ++i)
//         // 可行性剪枝
//         if (g[i] + a[cnt] <= len) {
//             g[i] += a[cnt];
//             if (dfs(cnt + 1)) return true;
//             g[i] -= a[cnt];
//         }

//     // 考虑新开一组
//     g[gcnt++] += a[cnt];
//     if (dfs(cnt + 1)) return true;
//     g[--gcnt] -= a[cnt];

//     return false;
// }
// void solve() {
//     // 优化搜索顺序，人为规定最终每组长度后，类似小猫那道题，优先搜索长度更长的搜索空间更小
//     sort(a, a + n, [](int a, int b) -> bool {return a > b;});

//     // 枚举分成的组数，分组越多每组长度越小，每组最小长度要满足>当前长度中的最大值，即至多分组数为sum/maxx
//     for (int i = sum / maxx; i; --i) {
//         len = sum / i;

//         gcnt = 0;
//         memset(g, 0, sizeof g);
//         if (dfs(0)) {
//             cout << len << endl;
//             return;
//         }
//     }
//     return;
// }
// int main() {
//     while (cin >> n, n) {
//         maxx = sum = 0;
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//             sum += a[i];
//             maxx = max(maxx, a[i]);
//         }
//         solve();
//     }
    
//     return 0;
// }

#include <iostream>

using namespace std;

constexpr int N = 70;

int n;
int l[N], sum;

void solve() {
    // 优化搜索顺序
    sort(l, l + n, [](int a, int b) -> bool {return a > b;});
    
    // 枚举组数
    

}
int main() {
    while (cin >> n, n) {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            sum += l[i];
        }
        solve();
    } 
    return 0;
}