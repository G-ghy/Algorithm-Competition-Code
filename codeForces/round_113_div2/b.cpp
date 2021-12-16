/**
 * 1. n个人
 * 2. 每一个人与其它所有人玩一次游戏
 * 3. 游戏结束条件：1.一个人赢了 2.两个人平了
 * 4. 玩家类型：1.希望一场都不输(赢或平)02.希望赢至少一场
 * 
 * 起初想法是赋给每个点一个“最终成绩g”，赢记为+1，输记为-1，平局记为0
 * 第一类节点应满足g>=0，第二类节点应满足g>=1
 * 边权值设为对边的起点的收益值
 * 对于每一个节点，出度和-入度和应满足g的要求
 * 显然构成的方程组符合差分约束的形式，求解可得每个点的出度和，入度和的一种可行解
 * 将出度和，入度和转换为关于边权的多元一次方程，求解即可获得各个边的边权
 * 差分约束求解出度和，入度和没有问题，但最后一步的多元一次方程组不会求解
 * 
 * 正解的考虑是：
 * 通过仔细分析不同节点的要求，可以发现
 * type1节点只会与type1节点和type2节点做游戏，type1只能赢或平，因此type1对type1的结果只能为平
 * type2节点只会与type1节点和type2节点做游戏，type2至少赢一局，type1不能输，则type2赢的只能为type2
 * type1对type1平局无论如何都是可以满足的
 * 因此可以发现，问题是否有解等价于每个type2是否都能满足赢1场，当type2个数>=3时，可以成环相互赢，各自满足赢一场；当type2个数<=2时，无法满足
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

const int N = 60;

int n;
int cnt1, box1[N];
int cnt2, box2[N];
string s;
char res[N][N];

int main()
{
    int T;
    cin >> T;
    while (T --)
    {
        cnt1 = cnt2 = 0;
        cin >> n;
        cin >> s;
        for (int i = 0; i < s.size(); ++ i)
        {
            if (s[i] == '1') box1[++ cnt1] = i + 1;
            else box2[++ cnt2] = i + 1;
        }

        if (cnt2 == 1 || cnt2 == 2) cout << "NO" << endl;
        else
        {
            for (int i = 1; i <= cnt1; ++ i)
                for (int j = i; j <= cnt1; ++ j)
                {
                    int a = box1[i], b = box1[j];
                    if (a == b) res[a][b] = res[b][a] = 'X';
                    else res[a][b] = res[b][a] = '=';
                }
            
            for (int i = 1; i <= cnt2; ++ i)
                for (int j = i; j <= cnt2; ++ j)
                {
                    int a = box2[i], b = box2[j];
                    if (a == b) res[a][b] = res[b][a] = 'X';
                    else
                    {
                        if (j == i + 1)
                        {
                            res[a][b] = '+';
                            res[b][a] = '-';
                        }
                        else if (j == cnt2)
                        {
                            res[a][b] = '-';
                            res[b][a] = '+';
                        }
                        else res[a][b] = res[b][a] = '=';
                    }
                }

            for (int i = 1; i <= cnt1; ++ i)
                for (int j = 1; j <= cnt2; ++ j)    
                {
                    int a = box1[i], b = box2[j];
                    res[a][b] = '+';
                    res[b][a] = '-';
                }

            cout << "YES" << endl;
            for (int i = 1; i <= n; ++ i)
            {
                for (int j = 1; j <= n; ++ j)
                    cout << res[i][j];
                cout << endl;
            }
        }
    }
    return 0;
}