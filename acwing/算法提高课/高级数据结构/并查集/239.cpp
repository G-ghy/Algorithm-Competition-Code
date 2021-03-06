// #include <cstring>
// #include <cstdio>
// #include <cmath>
// #include <iostream>
// #include<string>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <stack>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;

// constexpr int N = 10010;
// constexpr int INF = 0x3f3f3f3f;

// // 初做这道题是不会的，但是还是有一些感觉在
// // 1. 判断是否非法关键在于找到一个评判条件，本题中显然就是1的个数的奇偶
// // 2. 没想出来的就是在给定一个条件时应该怎么维护这个条件
// //      但是我发现判断一个条件是不是合法的，如果已知区间左端点以前1个数的奇偶同时已知区间右端点以前1个数的奇偶，显然就可以计算出给定区间1个数的奇偶，与所给条件进行比较即可得知该条件是否合法
// //      问题在于不知道如何维护左右端点以前1个数的信息(如果这种判断方法是正确的，那么这里应该是用并查集维护，没想出来是怎么维护的，要么不会这种方法)
// // 
// // 我考虑到了解决问题的关键可能在区间两个端点上，但是我的最初想法是标定一个位置之前1的个数是奇还是偶数
// // 这样标定区间中间是无法标定的，也就没办法往后继续做了
// // 我忽略的一点是，这是一个01序列，[L, R]中1的个数为奇数(偶数) <=> s[R] - s[L - 1]为奇数(偶数)(s为前缀和数组)
// // 说实话，分析到上面这一步还是有可能的，下面的步骤纯粹是靠经验积累了
// // 需要由s[R] - s[L - 1]为奇数推导出s[R]和s[L - 1]奇偶性不同
// // 也就是说s[R]和s[L - 1]应当处在两个集合中

// // 一般并查集内部只能维护一种关系
// // 带权并查集，在一个并查集内，通过边权实现多个关系的维护
// // 所有点都在这个集合里面，通过与根节点的距离表示与根节点的关系
// // 首先问题需要做一步转化，单从区间内1个数的奇偶无论如何也联系不到并查集上
// // 考虑统计区间内的计数问题，显然是采用并查集
// // 设s[i]为序列中从1到i这段子序列中1的个数
// // 因此s[a, b]中有奇数个1 <=> s[b] - s[a - 1] = 奇数
// // s[a, b]中有偶数个1 <=> s[b] - s[a - 1] = 偶数
// // 下面是灵魂的一步
// // 偶数 +- 偶数 = 偶数
// // 奇数 +- 奇数 = 偶数
// // 偶数 +- 奇数 = 奇数
// // 换言之，当s[b] - s[a - 1] = 奇数时，说明两者具有不同的奇偶性
// // 当s[b] - s[a - 1] = 偶数时，两者具有相同的奇偶性
// // 到这里，成功将1的个数的奇偶转化为了元素之间的关系
// // 元素之间的关系就可以通过并查集进行维护了
 
// // 观察数据范围可以发现，给定的l和r是在1e9范围内的，而问题的总数只有1e5
// // 由于需要使用l和r作为数组下标，1e9的范围显然是用普通数组无法解决的，一种方法是采用unordered_map代替一般数组
// // 另一种方式是将l和r进行离散化，离散化的结果处在[1，2e5](因为总共1e5个l和r数对，假设都不相同，那么最多就到2e5)
// // 在离散化这里还是遇到一点点思维上理解的困难，因为我认为离散化需要保留原数之间的大小关系，比如给定了
// // 1 5 even
// // 2 4 odd
// // 难道在并查集中维护时，不需要保证5这个元素是大于4这个元素的吗？
// // 答案是不需要，之所以会有这个问题，是因为我还是没有想清楚并查集维护的到底是什么，我们维护的是1和5这两个点之间的奇偶性关系以及2和4这两个点之间的奇偶性关系
// // 我们维护的不是一个区间，我们也不需要考虑说1和5之间1的个数，2和4之间1的个数，如果想的是这个就错了，上面的分析过程就是把一个区间的问题转化为了两个点之间的关系问题
// // 这里我们维护的只是点之间的关系，也就是说我们只需要唯一标定出1，5，2，4这几个点即可，至于用哪个标号来表示都是无所谓的

// // 本次与以往并查集不同的是，此时需要维护“具有相同奇偶性”和“具有不同奇偶性”两种关系
// // 我能想到的是维护两个并查集，一个维护具有相同奇偶性的元素，另一个维护具有不同奇偶性的元素
// // 下面是这种想法的代码实现，实现之后发现一个问题时，元素之间存在着传递关系，分成两个并查集没有办法处理这种传递关系(当传递关系跨越并查集之间时无法处理，例如给定x和y相同奇偶性，y和z不同奇偶性，此时x和y处在same并查集中，y和z处在diff并查集中，若要判断x和z相同奇偶性是否合法显然要去到diff中查找x和z的关系，但是x和z的关系存在于same和diff之间)
// // 其实在237一题中我就曾经考虑过这种方式，当时的问题是不等关系的并查集初始化存在问题，所以就想到先用并查集维护相等关系，然后判断是否存在非法的不等关系
// // 237题也是两种关系，相等和不等，本题也是两种关系，区别在于237只是询问所有条件是否无冲突，
// // 因此可以把一种关系全部维护完毕再检查另一种，因此不需要考虑元素之间的传递关系，因为关系全都维护完了，传递关系已经处在集合之中了
// // 但是本题询问在第几个条件处出现矛盾，并不能先把一种关系处理完再看另一种，因此传递关系并没有处理完成，所以需要随着条件的加入时时维护传递关系
// // 传递关系是使用两个并查集无法维护的，这也正是下面代码的问题所在

// // 由于需要时时维护集合中元素之间的关系(包含直接关系和间接关系)，通过添加边权来表示元素之间的关系
// // 用d[i]表示点i距离路径压缩后的父节点之间的距离，0表示具有相同奇偶性，1表示具有不同奇偶性
// // 两点之间的关系如下
// // (d[x] + d[y]) % 2 == 0 (<=> d[x] ^ d[y] == 0): x和y具有相同奇偶性
// // (d[x] + d[y]) % 2 == 1 (<=> d[x] ^ d[y] == 1): x和y具有不同奇偶性
// // 在原有并查集的基础上加入对于边权的维护，从而可以维护点与点之间的关系

// // 2种关系通过%2表示，3种关系则通过%3表示，依此类推
// int n, m;
// int p[N], d[N];
// // int same[N], diff[N];
// unordered_map<int, int> s;

// inline int get(int x) {
//     if (!s.count(x)) s[x] = ++n;
//     return s[x];
// }
// // int find(int x, int p[]) {
// //     if (p[x] != x) p[x] = find(p[x], p);
// //     return p[x];
// // }
// int find(int x) {
//     if (p[x] != x) {
//         int root = find(p[x]);
//         // 上一步将p[x]到root的路径压缩完成
//         d[x] ^= d[p[x]]; // x -> p[x] -> root
//         p[x] = root;
//     }
//     return p[x];
// }
// void solve() {
//     cin >> n >> m;
//     n = 0;

//     for (int i = 0; i < N; ++i) p[i] = i;

//     int res = m;
//     for (int i = 1; i <= m; ++i) {
//         int l, r;
//         string type;
//         cin >> l >> r >> type;
//         l = get(l - 1), r = get(r);
//         int pl = find(l), pr = find(r);

//         if (type == "even") { // 相同奇偶性，如果并查集中pl != pr则一定不会发生矛盾，添加相同关系即可，若pl == pr, 需要查看并查集中保存的关系是否与此时给定的条件矛盾
//             if (pl != pr) {
//                 p[pl] = pr;
//                 d[pl] = d[l] ^ d[r]; // 原来有两条路径 l -> pl, 路径长度为d[l]; r -> pr，路径长度为d[r]；此时需要将pl连接到pr上，所以增加一条路径是 pl -> pr, 路径长度为d[pl], 此时l和r之间的关系为(d[l] ^ d[pl] ^ d[r])，因为l和r具有相同奇偶性，所以需要保证这个值为0，根据异或的性质令d[pl] = d[l] ^ d[r]即可
//             } else {
//                 if (d[l] ^ d[r] == 1) { // 并查集中维护的是l和r具有不同奇偶性，与此时条件矛盾
//                     res = i - 1;
//                     break;
//                 }
//             }
//         } else { // 不同奇偶性
//             if (pl != pr) {
//                 p[pl] = pr;
//                 d[pl] = d[l] ^ d[r] ^ 1;
//             } else {
//                 if (d[l] ^ d[r] == 0) { // 并查集中维护的是l和r具有不同奇偶性，与此时条件矛盾
//                     res = i - 1;
//                     break;
//                 }
//             }
//         }

//         // 上述代码存在太多重复部分，可以做出如下等价变形
//         // int t = 0;
//         // if (type == "odd") t = 1;
//         // if (pl != pr) {
//         //     p[pl] = pr;
//         //     d[pl] = d[l] ^ d[r] ^ t;
//         // } else {
//         //     if (d[l] ^ d[r] != t) {
//         //         res = i - 1;
//         //         break;
//         //     }
//         // }
//     }

//     cout << res << '\n';
// }
// void solve() {
//     cin >> n >> m;
//     n = 0; // 离散化仍然使用n作为点数,所以此处初始为0

//     // 并查集初始化
//     for (int i = 0; i < N; ++i) same[i] = diff[i] = i;

//     int res = m; // 若不存在非法条件则答案为m
//     for (int i = 1; i <= m; ++i) {
//         int l, r;
//         string type;
//         cin >> l >> r >> type;
//         l = get(l - 1), r = get(r);

//         if (type == "even") { // 相同奇偶性，加入到same中，同时检查是否存在于diff中
//             int pl = find(l, diff), pr = find(r, diff);
//             if (pl == pr) {
//                 res = i - 1; // 在第i个条件出现矛盾，则只能解决到底i-1个条件
//                 break;
//             }
//             same[pl] = pr;
//         } else { // 不同奇偶性，加入到diff中，同时检查是否存在于same中
//             int pl = find(l, same), pr = find(r, same);
//             if (pl == pr) {
//                 res = i - 1; // 在第i个条件出现矛盾，则只能解决到底i-1个条件
//                 break;
//             }
//             diff[pl] = pr;
//         }
//     }

//     cout << res << '\n';   
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     solve();
//     return 0;
// }


// 带扩展域并查集
// 本题元素之间的关系为具有相同奇偶性或具有不同奇偶性，因此在带权并查集之前我有一种想法是维护两个并查集，分别保存具有相同奇偶性的元素和不同奇偶性的元素
// 但是出现的问题是，传递关系无法维护，如果待查元素关系是由两个并查集共同带来的是无法直接查询得出的
// 现在想来，之所以出现传递关系无法维护的问题，是由于一个完整的关系链是覆盖两个并查集的，如果想要维护传递关系，必须保证传递关系处在一个并查集内部
// 所以我的思想本身就是有问题的，带扩展域并查集并非对我的原有思想的完善
// 带扩展域并查集的思考方式为：
// 本题中的元素有2种可能的取值，1.奇数 2.偶数
// 假设有n个元素，则i(1 <= i <= N)表示第i个元素为偶数，i + n表示第i个元素为奇数(数值和含义是任意的，用i表示奇数，i+n表示偶数同样可以)
// 如果两元素a和b的奇偶性相同，那么通过条件a为偶数，可以推导出b为偶数，即将a和b进行合并，同时通过a为奇数，可以推导出b为奇数，即将a+n和b+n进行合并；同理如果奇偶性不同，也分为两种情况
// 这里的i和i+n仍还还是两个数值，在一般并查集和带权并查集中数值代表的都是某个元素(第i个元素)，但是在带扩展域并查集中这个数值代表元素的一个条件(第i个元素的值为偶数)
// 而从i+n到2i + n就是一个扩展出来的区域，即扩展域，当然这里的n并非严格要求，只需要保证和另一个区域的数值不同即可
// 所以这里开辟的多个区域并非通过添加并查集，仍然采用一个并查集，但是把所有条件都放入到该并查集中，增加的是逻辑区域而并非物理区域
// 而唯一的并查集也保证了传递关系得以正确保存
// 增加逻辑区域非物理区域这一点乍一想不难理解，但是一想把这些条件都放入到一个并查集中就变得有些模糊了
// 为了消除这种模糊的感觉，以下面的描述为例：
// 对于x和y奇偶性相同这个条件，保存到并查集中是这样的：
// 将x是偶数的条件，即x 和 y是偶数的条件，即y 进行合并
// 将x是奇数的条件，即x+n 和 y是奇数的条件，即y+n 进行合并
// 也就是说x和y进行了合并，x+n和y+n进行了合并，如果这时候将关系图抽象为一张图，就相当于x和y处在一个连通块中，x+n和y+n处在一个连通块中
// 一般并查集和带权并查集维护元素之间的关系，带扩展域并查集维护哪些条件之间可以相互推导出

#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

constexpr int N = 20010, offset = N >> 1; // 5000个条件，每个条件2个点，考虑离散化后最多点数即10000个点，由于需要添加扩展域，需要额外的10000个点
constexpr int INF = 0x3f3f3f3f;

int n, m;
int p[N];
unordered_map<int, int> s;

inline int get(int x) {
    if (!s.count(x)) s[x] = n++;
    return s[x];
}
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve() {
    cin >> n >> m;
    n = 0;
    for (int i = 0; i < N; ++i) p[i] = i;

    int res = m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        string type;
        cin >> a >> b >> type;
        a = get(a - 1), b = get(b);

        int a_even = find(a), b_even = find(b); // a为偶数，b为偶数
        int a_odd = find(a + offset), b_odd = find(b + offset); // a为奇数，b为奇数
        // 这里的偏移量之所以定为N/2是因为原区域最多有N/2个元素，新开区域编号要从N/2开始

        if (type == "even") { // 相同奇偶性 a为偶数推导出b为偶数，a为奇数->b为奇数
            if (a_even == b_odd) { // 这里a_even == b_odd 和 b_even == a_odd是等价的，两者一定同时出现，判断其一即可
                res = i - 1;
                break;
            }
            // 此前不曾保存关系 或 此前已经保存了奇偶性相同的关系 均采取合并操作即可
            // 当a和b具有相同奇偶性时可以得到的两个条件
            p[a_even] = b_even; // a为偶 -> b为偶
            p[a_odd] = b_odd; // a为奇 -> b为奇
        } else { // 不同奇偶性，对照上方修改即可
            if (a_even == b_even) {
                res = i - 1;
                break;
            }
            p[a_even] = b_odd;
            p[a_odd] = b_even;
        }
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}