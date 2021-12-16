#include <iostream>
#include <vector>

using namespace std;

const int N = 1600, MOD = 555555555;

int n, m, t;
int c[N][N];
int res[N], cnt;
vector<int> affectedRow;
vector<int> affectedCol;
int rcnt[N], ccnt[N];

void init()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j)
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
}
inline bool check(int row, int col) // 改变的行数，列数
{
    return ((m - 2 * col) * row + n * col == t);
}
void dfs(int total, int capa, int boxcnt, vector<int> &affectedLine)
{
    if (boxcnt == total + 1)
    {
        if (capa) return ;
        
        for (int i = 0; i < cnt; ++i) cout << res[i] << ' ';
        cout << endl;
        int line = 0;
        for (int i = 0; i < cnt; ++i)
            if (res[i] & 1) ++line;
        affectedLine.push_back(line);
        return ;
    }

    for (int i = 0; i <= capa; ++i)
    {
        res[cnt++] = i;
        dfs(total, capa - i, boxcnt + 1, affectedLine);
        --cnt;
    }
}
int main()
{
    int row, col;
    cin >> n >> m >> row >> col >> t;

    init();

    int res = 0;
    // 对同一行或列可以实行多次重复操作，换来换去的也是可以的
    /**
     * 超时就是因为dfs搜索了很多无效空间，而我们dfs的本质目的在于
     * 找到修改不同行数的总方案数
     * 和
     * 修改不同列数的总方案数
     * 
     * 最后的枚举过程已经不能在优化了，因为判断问题是否有解一定需要枚举所有可能的行列方案组合
     * TLE的关键在于如何快速找到上述2个问题
     * 
     */
    cnt = 0;
    dfs(n, row, 1, affectedRow);
    cnt = 0;
    dfs(m, col, 1, affectedCol);

    for (int row : affectedRow) ++rcnt[row];
    for (int col : affectedCol) ++ccnt[col];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j <N; ++j)
            if (rcnt[i] && ccnt[j])
                if (check(i, j)) res = (res + (1ll * rcnt[i] * ccnt[j]) % MOD) % MOD;

    cout << res << endl;

    return 0;
}