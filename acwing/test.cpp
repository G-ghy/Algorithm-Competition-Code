#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

constexpr int N = 10;
constexpr int INF = 0x3f3f3f3f;

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void solve() {
  cout << (-6 % 3) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  solve();
  return 0;
}