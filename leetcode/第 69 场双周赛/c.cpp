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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    unordered_map<string, int> ma;

    int longestPalindrome(vector<string>& words) {
        // leetcode上map可能没办法自己完成初始化，被这个问题坑了有1个小时
        for (char i = 'a'; i <= 'z'; ++i)
            for (char j = 'a'; j <= 'z'; ++j)
                ma[to_string(i) + to_string(j)]  = 0;

        for (string word : words) ++ma[word];

        int res = 0;
        for (auto count : ma) {
            string word = count.first;
            int cnt = count.second;
            if (!cnt) continue;

            string t = word;
            reverse(t.begin(), t.end());
            if (!ma[t]) continue;

            if (word != t) {
                int num = min(cnt, ma[t]);
                res += num * 4;
                ma[word] -= num;
                ma[t] -= num;
            }
            // word == t && cnt 是偶数
            else if (!(cnt & 1)) {
                res += cnt * 2;
                ma[word] = 0;
            }
            // word == t && cnt 是大于2的奇数
            else if (cnt > 2) {
                res += (cnt - 1) * 2;
                ma[word] = 1;
            }
        }

        for (auto count : ma) {
            string word = count.first;
            int cnt = count.second;

            string t = word;
            reverse(t.begin(), t.end());

            if (word == t && cnt == 1) {
                res += 2;
                break;
            }
        }
        return res;
    }
};

void solve() {
    Solution solution;
    vector<string> vec = {"oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig","jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss","tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo","bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff","ss","gi","yy","gb","mm","pp","uu","kk","jj","ee"};
    cout << solution.longestPalindrome(vec);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}