#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 1e5 + 10;

int n;
int son[N][26], cnt[N];
int idx;

void insert(string str) {
    int p = 0;
    for (char c : str) {
        int u = c - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u]; 
    }
    ++cnt[p];
}
int query(string str) {
    int p = 0;
    for (char c : str) {
        int u = c - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char op;
        string str;
        cin >> op >> str;

        if (op == 'I') {
            insert(str);
        } else {
            cout << query(str) << '\n';
        }
    }
}
int main() {
    solve();
    return 0;
}

int main() {
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); ++i) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];

        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);

    int t = 0;
    for (int i = 0; i < A.size(); ++i) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        t = (t < 0);
    }
    while (C.size() > 1 && !C.back()) C.pop_back();

    int t = 0;
    for (int i = 0; i < A.size() || t; ++i) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && !C.back()) C.pop_back();
}

int main() {
    // add
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); ++i) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);

    //sub
    int t = 0;
    for (int i = 0; i < A.size(); ++i) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        t = (t < 0);
    }
    while (C.size() > 1 && !C.back()) C.pop_back();

    // mul
    int t = 0;
    for (int i = 0; i < A.size() || t; ++i) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && !C.back()) C.pop_back();

}

int merge_sort(int a[], int l, int r) {
    if (l >= r) return 0;

    int mid = l + r >> 1;
    int res = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);

    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            res += mid - i + 1;
            tmp[k++] = a[j++];
        }
    }

    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
}

int quick_sort(int a[], int l, int r, int k) {
    if (l >= r) return a[l];

    int x = a[l + r >> 1], i = l - 1, j = r + 1;

    while (i < j) {
        while (a[++i] < x);
        while (a[--j] > x);
        if (i < j) swap(a[i], a[j]);
    }

    int sl = j - l + 1;
    if (k <= sl) quick_sort(a, l, j, k);
    else quick_sort(a, j + 1, r, k - sl);

}

void get_primes(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; ++j) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}