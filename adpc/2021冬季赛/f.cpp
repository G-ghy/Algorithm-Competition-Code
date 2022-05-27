// 凸包
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
#include <cstdio>

using namespace std;

constexpr int maxn = 110;

int n;
int x[maxn],y[maxn];
double p[maxn];

bool judge(int i,int j,int k) {
    return ((x[j]-x[i]) * (y[k]-y[i]) - (y[j]-y[i])*(x[k]-x[i])) < 0;
}

void solve() {
    cin >> n;
    double ans=0.0;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i] >> p[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j) {
                double q=p[i]*p[j];
                for (int k=1;k<=n;k++)
                    if ((k!=i)&&(k!=j)&&(judge(i,j,k)))
                        q*=1-p[k];
                ans+=q*(x[i]*y[j]-y[i]*x[j]);
            }

    ans /= 2;
    printf("%.6f", ans + 1e-8);
}
int main() {
    solve();
    return 0;
}