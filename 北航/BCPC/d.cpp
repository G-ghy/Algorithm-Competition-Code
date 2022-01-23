/**
 * 做法很简单，只需要保证攻击方始终处于最优状态，而防守方始终处于最劣状态
 * 查看此时攻击方是否可以战胜防守方
 * 
 * 太繁琐了，要吐了
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

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

struct Attribute {
    int hp;
    int attack;
    int defense;
    int sattack;
    int sdefense;
    int speed;
} attribute[3]; // 0: 种族值； 1：个体值； 2：努力值

struct Object {
    int lv;
    int hp;
    int attack, sattack;
    int defense, sdefense;
    int speed;
    int ppower[2], pcnt; // 物理招式威力
    int spower[2], scnt; // 特殊招式威力
} object[N];

int n;

void get_attr_info(int inx, string attr) {
    int hp;
    int attack, sattack;
    int defense, sdefense;
    int speed;

    int a[6];
    int begin = 0, pos;
    for (int i = 0; i < 5; ++i) {
        pos = attr.find(begin, '/');
        a[i] = stoi(attr.substr(begin, (int)pos - begin));
        begin = pos + 1;
    }
    hp = a[0];
    attack = a[1]; defense = a[2];
    sattack = a[3]; sdefense = a[4];
    speed = a[5];
    attribute[inx] = {hp, attack, defense, sattack, sdefense, speed};
}
void get_power_info(int inx, string power_type) {
    int pos = power_type.find('/');
    int power = stoi(power_type.substr(2, pos));
    string type = power_type.substr(pos + 1);
    if (type == "Physical") {
        object[inx].ppower[object[inx].pcnt++] = power;
    } else {
        object[inx].spower[object[inx].scnt++] = power;
    }
}
void compute_attr(int inx) {
    int lv = object[inx].lv;

    auto ss = attribute[0];
    auto iv = attribute[1];
    auto ev = attribute[2];
    object[inx].hp = (ss.hp * 2 + iv.hp + ev.hp / 4) * lv / 100 + 10 + lv;
    object[inx].attack = (ss.attack * 2 + iv.attack + ev.attack / 4) * lv / 100 + 5;
    object[inx].sattack = (ss.sattack * 2 + iv.sattack + ev.sattack / 4) * lv / 100 + 5;
    object[inx].defense = (ss.defense * 2 + iv.defense + ev.defense / 4) * lv / 100 + 5;
    object[inx].sdefense = (ss.sdefense * 2 + iv.sdefense + ev.sdefense / 4) * lv / 100 + 5;
    object[inx].speed = (ss.speed * 2 + iv.speed + ev.speed / 4) * lv / 100 + 5;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> object[i].lv;
        string ss, iv, ev;
        cin >> ss >> iv >> ev;
        cout << ss << endl << iv << endl << ev << endl;
        get_attr_info(0, ss);
        get_attr_info(1, iv);
        get_attr_info(2, ev);

        compute_attr(i);

        string power_type;
        for (int j = 0; j < 4; ++j) {
            cin >> power_type;
            get_power_info(i, power_type);
        }
    }

    

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}