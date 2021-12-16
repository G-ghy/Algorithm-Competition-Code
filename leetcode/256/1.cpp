#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>

using namespace std;

auto op1 = [](int a, int b) -> int {return a + b;};

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        bool st[1010];
        int dis[1010];
        queue<int> q;
        queue<int> rq;
        auto op1 = [](int a, int b) -> int {return a + b;};
        auto op2 = [](int a, int b) -> int {return a - b;};
        auto op3 = [](int a, int b) -> int {return a ^ b;};
        vector<function<int(int, int)>> ops = {op1, op2, op3};

        memset(st, 0, sizeof st);
        memset(dis, 0, sizeof dis);
        dis[start] = 0;
        st[start] = true;
        q.emplace(start);
        dis[goal] = 0;
        st[goal] = true;
        rq.emplace(goal);

        int x;
        int flag;
        while (q.size() && rq.size()) {
            if (q.size() <= rq.size()) {
                flag = 0;
                x = q.front(); 
                q.pop();
            } else {
                flag = 1;
                x = rq.front();
                rq.pop();
            }

            for (int dx : nums) {
                for (auto &f : ops) {
                    int nx = f(x, dx);
                    if (st[nx]) return dis[nx] + dis[x] + 1;
                    if (nx >= 0 && nx <= 1000 && !st[nx]) {
                        st[nx] = true;
                        dis[nx] = dis[x] + 1;
                        if (!flag) q.emplace(nx);
                        else rq.emplace(nx); 
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    
    Solution so;
    vector<int> nums = {2,4,12};
    int start = 2, goal = 12;

    cout << so.minimumOperations(nums, start, goal) << endl;

    return 0;
}