/**
 * 不考虑优化，枚举每一个空位，每个空位枚举1到9，所有空位填满后判断整张图是不是合法的
 * 考虑优化，每个空位在搜索之前就已经可以确定它可能的值了，1到9的数字排除掉行中，列中，3*3方格中已经有的数字，剩下的是该空位可能的值
 * 仍枚举每个空位，但每个空位仅枚举其可能的值，一边填一遍检查，因为填满后也是要查，填充时检查还能减少搜索空间
 *
 * 不管怎么优化，我最初的观察视角本身就存在着一定的问题，我是按照一维的视图去计算各个数据，就像下面那些函数一样，写起来较为复杂，不妨直接在最开始就映射到二维空间上，之后的各个操作直接在二维空间进行
 * 这样说不太准确，可以不真的映射到二维空间，但是我们思考问题的角度应当是处在二维空间上的
 * 
 * 对于多个对象共有的属性，维护该属性要比维护每一个对象简单的多
 * 对于减小可选择空间，我考虑的是维护每个空白点可选择的空间，这样比较麻烦，不如直接维护每一行，每一列，每一个九宫格可选择的空间，取交集就是一个点的可选择空间
 * 维护每个点的可选择空间，只能把所有空白格子填充完成后再统计判定当前填充方法是否合法
 * 一方面，很可能在搜索途中就已经不合法了，但无法及时停止搜索；另一方面，维护每个点的信息的操作较为复杂
 * 
 * 优化搜索顺序：优先搜索可选择空间较小的点，把搜索空白点以及其可搜索空间大小用pair存储下来，可搜索空间大小作为first，从小到大排序一遍，顺次搜索
 * 
 * 1.首先把一维空间映射为二维空间
 * 2.预处理每一行，每一列，每一个九宫格的可选择空间，为了取交集的方便，采用二进制的思维进行存储，可以仅是把一个int变量以二进制的形式进行处理，也可以采用bitset
 * 3.把所有空白点及其可选择空间大小以pair形式进行存储，按照可选择空间大小从小到大排序
 * 4.对空白点逐一进行dfs，每次dfs枚举其可选择空间，采用lowbit运算进行优化
 * 5.如果某个空白点的可选择空间为空，说明该填充方法不合法，直接返回
 *   如果搜索完所有空白点，那么搜索结束，一路返回
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 9;

char str[100];
int row[N], col[N], cell[3][3]; // 当作二进制数，1表示可选择，0表示不可选择
int oneNum[1 << N], mapping[1 << N];

inline int lowbit(int x) {
    return x & -x;
}
inline int getSelectSpace(int x, int y) { // 返回点(x, y)可选择空间，为一二进制数
    return row[x] & col[y] & cell[x / 3][y / 3]; // 同理，横坐坐标转换为方格坐标注意坐标转换
}
inline void init() { // 初始化row，col，cell全部位置为可选择，之后根据str[]修改row,col,cell的标记
    for (int i = 0; i < N; ++i)
        row[i] = col[i] = (1 << N) - 1; // 二进制下：1000000000 - 1 = 111111111

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cell[i][j] = (1 << N) - 1;

    for (int i = 0, k = 0; i < N; ++i)
        for (int j = 0; j < N; ++j, ++k)
            if (str[k] != '.') {
                int t = str[k] - '1';
                row[i] -= 1 << t;
                col[j] -= 1 << t;
                cell[i / 3][j / 3] -= 1 << t; // i, j 是横纵坐标，转换为3*3方格时注意坐标变换
            }
    // for (int i = 0; i < 81; ++i)
        // if (str[i] != '.') {
        //     int r = i / 9; // 一维空间映射到二维空间的行数
        //     int c = i % 9; // 一维空间映射到二维空间的列数
        //     int cell_x = r / 3, cell_y = c / 3;
        //     int t = str[i] - '1'; // row，col和cell标识的是0到8中哪些数字可选择，而str中的数字是0到9，需要映射到0到8，所以是-'1'，而非-'0'
        //     row[r] -= 1 << t; // 如果t==0已经被选择了，那么标记第0位，即1<<t
        //     col[c] -= 1 << t;
        //     cell[cell_x][cell_y] -= 1 << t;
        // }
}
bool dfs(int cnt) { // 搜索第cnt个空白点
    if (!cnt) return true;

    // 寻找可搜索空间最小的点
    int x, y, minn = 10; // 最大搜索空间为1到9，9个数
    for (int i = 0, k = 0; i < N; ++i)
        for (int j = 0; j < N; ++j, ++k)
            if (str[k] == '.') {
                int spaceSize = oneNum[getSelectSpace(i, j)]; // 返回值为表示可选择空间的二进制数，真实可选择空间大小为其中1的个数，多次查询，因此做下预处理
                if (spaceSize < minn) {
                    minn = spaceSize;
                    x = i, y = j;
                }
            }

    // 获取到可搜索空间最小的点开始枚举其搜索空间
    int space = getSelectSpace(x, y);
    // if (!space) return false; // 一个空白点的可搜索空间为0说明已经不合法了，即使不写下面的for也不会执行，还是会直接返回false
    for (int i = space; i; i -= lowbit(i)) { // 当i为0时，就不需要再处理了，错误原因在于写的是~i <=> i >= 0，多操作了一次
        // 此时的i是表示可搜索空间的二进制数，需要找到最后一位1所对应的数字
        // 取最后一位1可以采用lowbit，1000，lowbit取出的值为8，但是实际对应的可选择的值为3，这里采用预处理的方式标识1，10，100，1000等标识的可选择值
        int t = mapping[lowbit(i)]; // t即为可选择的值
        row[x] -= 1 << t;
        col[y] -= 1 << t;
        cell[x / 3][y / 3] -= 1 << t;
        str[x * N + y] = t + '1';

        if (dfs(cnt - 1)) return true;

        row[x] += 1 << t;
        col[y] += 1 << t;
        cell[x / 3][y / 3] += 1 << t;
        str[x * N + y] = '.';
    }

    return false;
}
void solve() {
    init();

    int cnt = 0;
    for (int i = 0; i < 81; ++i)
        if (str[i] == '.') ++cnt;

    dfs(cnt);

    // 题目保证一定有解，因此dfs之后str保存的就是答案
    printf("%s\n", str);
}
int main() {
    for (int i = 0; i < N; ++i) mapping[1 << i] = i;
    for (int i = 0; i < 1 << N; ++i)
        for (int j = 0; j < N; ++j)
            oneNum[i] += (i >> j) & 1;

    while (cin >> str, str[0] != 'e') solve();
    return 0;
}
// struct Node {
//     int x;
//     int r, c;
//     int rs, re;
//     int cs, ce;
//     int s;
// } nodes[N];

// void init(Node n) {
//     n.rs = n.x / 9 * 9;
//     n.re = (n.x / 9 + 1) * 9 - 1;
//     n.cs = n.x - n.rs;
//     n.ce = (n.x - n.rs) + 72;
//     n.r = n.x / 9;
//     n.c = n.x % 9;
//     n.s = n.r / 3 * 27 + n.c / 3 * 3;
// }
// bool checkRow() {
//     memset(st, 0, sizeof st);
//     for (int i = rs; i <= re; ++i) {
//         ++st[str[i] - '0'];
//         if (st[str[i] - '0'] > 1) return false;
//     }
//     return true;
// }
// bool checkCol() {
//     memset(st, 0, sizeof st);
//     for (int i = cs; i <= ce; i += 9) {
//         ++st[str[i] - '0'];
//         if (st[str[i] - '0'] > 1) return false;
//     }
//     return true;
// }
// bool checkVertex() {
//     memset(st, 0, sizeof st);
//     for (int i = s; i <= s + 18; i += 9)
//         for (int j = 0; j <= 2; ++j) {
//             ++st[str[i + j] - '0'];
//             if (st[str[i + j] - '0'] > 1) return false;
//         }
//     return true;
// }