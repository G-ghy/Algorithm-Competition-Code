// #include <cstring>
// #include <cstdio>
// #include <cmath>
// #include <iostream>
// #include<string>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;

// constexpr int N = 1e5 + 10;
// constexpr int INF = 0x3f3f3f3f;

// int capacity, ep, davg, n;
// vector<pair<int, double>> station; // <距离起点距离, 油价>
// double minCost;
// int maxDis;

// // pos:当前位置所在数组下标，s：剩余油量支持能走的距离， p：当前总花费
// void dfs(int pos, int surplus, double price) {
//     if (price > minCost) return;
//     if (station[pos].first == ep) {
//         minCost = min(minCost, price);
//         return;
//     }

//     bool flag = true; // 是否无路可走
//     for (int i = pos + 1; i < (int)station.size() &&
//                           station[i].first - station[pos].first <= capacity * davg; 
//                           ++i) {        
//         flag = false;
//         int dis = station[i].first - station[pos].first;
//         if (surplus >= dis) dfs(i, surplus - dis, price);
//         else {
//             price += ceil((dis - surplus) / davg) * station[pos].second;
//             surplus = ceil((dis - surplus) / davg) * davg - dis;
//             dfs(i, surplus, price);
//         }
//     }
//     if (flag) maxDis = max(maxDis, station[pos].first);
// }
// void solve() {
//     scanf("%d%d%d%d", &capacity, &ep, &davg, &n);
//     station.emplace_back(ep, 0);
//     for (int i = 0; i < n; ++i) {
//         double price;
//         int dis;
//         scanf("%lf%d", &price, &dis);
//         station.emplace_back(dis, price);
//     }
//     sort(station.begin(), station.end());

//     for (auto i : station) std::cout << i.first << ' ' << i.second << std::endl;
//     maxDis = 0;
//     minCost = __DBL_MAX__;
//     dfs(0, 0, 0);

//     if (minCost != __DBL_MAX__) printf("%.2lf\n", minCost);
//     else printf("The maximum travel distance = %.2lf\n", maxDis);
// }
// int main() {
//     solve();
//     return 0;
// }

/**
 * 每辆车一定是在加油站之间移动，如果停在非加油站位置显然是没有意义的
 * 当到达某个加油站时，需要考虑加油或是不加油，加油的话加多少
 * 
 * 上述代码的思路是dfs所有路径，但是是搜每个加油站
 * 如果两个加油站之间距离>油箱容量支持的最大距离，代码则认为两者不可达，但是可以通过中间加油站进行中转到达，dfs是没办法处理的
 * 
 * 还有一种思路是贪心
 * 对于当前加油站(设油价为p1)，假设当前油箱是满的，在能走到的所有加油站中选择一个价格最低的(设油价为p2),(这里有问题，应当遵循的原则是能少花则少花，例如油价是3 2 1，对于油价为3的站点，满油状态可以走到2和1，最优策略是先到2再到1而非直接从3到1，只要后续找到比当前油价更低的则到这里)
 * 若p1<=p2，则选择把油加满，然后走到油价为p2的站点
 * 否则，只加到可以走到油价为p2的加油站
 * 重复以上过程
 * 
 * 如果一个加油站满油状态可以到达终点，
 * 需要考虑是直接在此站加满油直接到终点，还是要经过其他站进行中转
 * 此时需要考虑当前油量是否可以直接到达终点
 * 1.未加满油即可到达终点则直接到达终点
 * 2.比较剩余站点中的最低油价和当前油价，若当前最低则在此站加油到恰好可以到达终点
 *                                 反之，先加到恰好可以到达更低油价的站点，然后到达终点
 *                                 这里可以证明不再需要进行第2次中转
 * 
 * 这道题被一个点坑了好久就是我总是认为加油量必须为整数，这也就意味着在一次加油过程中可能需要多加一个单位
 * 那自然每次都会出现多余的油，需要维护这个值
 * 实际上油量可以带小数，就是需要多少加多少就可以了
 * 
 * 总结来说就一句话：如果可以到价格更低的加油站加那就一定到那里去加，一分多余的钱都不花
 * 后续如果没有价格更低的就到价格最低的，但是现在就需要把油加满（第一次这里就没有想到）
 */

#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr double DOUBLE_INF = __DBL_MAX__;

double capacity, ep, davg, n;
vector<pair<double, double>> station; // <距离起点距离, 油价>

void solve() {
    scanf("%lf%lf%lf%lf", &capacity, &ep, &davg, &n);
    station.emplace_back(ep, 0);
    for (int i = 0; i < n; ++i) {
        double price, dis;
        scanf("%lf%lf", &price, &dis);
        station.emplace_back(dis, price);
    }
    sort(station.begin(), station.end());

    double nowDis = 0.0, nowPrice, totalPrice = 0.0, leftDis = 0.0; // 当加油时不一定可以加到刚刚好到达一个加油站，可能会多加
    if (station[0].first) {
        printf("The maximum travel distance = %.2lf\n", 0.00);
        return;
    } else nowPrice = station[0].second;
    
    // 此时在起点，要决定接下来走到哪里
    while (nowDis < ep) {
        double maxDis = nowDis + capacity * davg; // 当前位置能走到的最远位置
        bool flag = false; // 是否在nowDis的后续站点找到比当前油价更低的站点
        double minPrice = DOUBLE_INF, minPriceDis; // 维护后续站点中的油价最低值及其位置

        // 枚举后续节点，找到接下来可以走到哪里
        for (int i = 0; i <= n && station[i].first <= maxDis; ++i) {
            if (station[i].first <= nowDis) continue;
            if (station[i].second < minPrice) {
                minPrice = station[i].second;
                minPriceDis = station[i].first;
            }
            // 后续站点中找到比当前油价更低的了，则按照贪心的策略一定是先走到这里
            if (station[i].second < nowPrice) {
                flag = true;
                // 加油量可以是0.5个单位，不需要取整，算出来多少就是多少就可以了
                // totalPrice += ceil((station[i].first - nowDis - leftDis) / davg) * nowPrice;
                // leftDis = ceil((station[i].first - nowDis - leftDis) / davg) * davg - (station[i].first - nowDis - leftDis);
                totalPrice += (station[i].first - nowDis - leftDis) /davg * nowPrice;
                leftDis = 0.0; // 只有在加满油时可能有多余的情况，否则就是需要多少加多少，没有剩余的
                nowDis = station[i].first;
                nowPrice = station[i].second;
                break;
            }
        }

        /** 此时有以下几种可能
         * !flag时可能是在自己可走到的范围内没有点了，即无解了；也可能是没有找到比当前节点更小的值，但是可以走到一些点
         * - 有可达的站点
         *      1. 已经找到比当前站点油价更低的站点了，flag = true，不做操作
         *      2. 没有找到比当前站点油价更低的，但是还有有一个最低值，flag = false，minPrice有一个数值，加油至刚好可以到达这里
         * - 没有可达的站点
         *      flag = false， minPrice为INF，说明无解，程序结束
         */
        if (!flag && minPrice == DOUBLE_INF) {
            nowDis += capacity * davg;
            printf("The maximum travel distance = %.2lf\n", nowDis);
            return;
        }
        // 在nowDis满油的状态下能走到的加油站没有价格更低的，因此会选择在nowDis将油加满
        if (!flag && minPrice != DOUBLE_INF) {
            totalPrice += (capacity * davg - leftDis) / davg * nowPrice;
            leftDis = capacity * davg - (minPriceDis - nowDis);
            // totalPrice += ceil((capacity * davg - leftDis) / davg) * nowPrice;
            // leftDis = capacity * davg - (minPriceDis - nowDis);
            // totalPrice += ceil((minPriceDis - nowDis - leftDis) / davg) * nowPrice;
            // leftDis = ceil((minPriceDis - nowDis - leftDis) / davg) * davg - (minPriceDis - nowDis - leftDis);
            nowDis = minPriceDis;
            nowPrice = minPrice;
        }
    }

    printf("%.2lf\n", totalPrice);
}
int main() {
    solve();
    return 0;
}