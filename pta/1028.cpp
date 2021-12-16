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
#include <functional>

using namespace std;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

struct Person {
    string id;
    string name;
    int score;

    Person() {}
    Person(string id, string name, int score) : id(id), name(name), score(score) {}
};

auto cmp1 = [](Person &a, Person &b) -> bool {return a.id < b.id;};
auto cmp2 = [](Person &a, Person &b) -> bool {return a.name <= b.name;};
auto cmp3 = [](Person &a, Person &b) -> bool {
    if (a.score != b.score) return a.score <= b.score;
    if (a.name != b.name) return a.name <= b.name;
    return a.id < b.id;
};

int n, c;
vector<Person> person;
vector<function<bool(Person &, Person &)>> cmps = {cmp1, cmp2, cmp3};

void solve() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        string id, name;
        int score;
        cin >> id >> name >> score;
        person.emplace_back(id, name, score);
    }
    sort(person.begin(), person.end(), cmps[c - 1]);

    for (Person p : person) cout << p.id << ' ' << p.name << ' ' << p.score << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}