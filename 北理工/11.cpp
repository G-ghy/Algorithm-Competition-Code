// #include <bits/stdc++.h>

// using namespace std;
// using ULL = unsigned long long;

// unsigned long long k1, k2, K;

// void setSeed(unsigned long long a, unsigned long long b, unsigned long long c) {
//     k1 = a;
//     k2 = b;
//     K = c;
// }

// unsigned long long xorShift128Plus() {
//     unsigned long long k3 = k1, k4 = k2;
//     k1 = k4;
//     k3 ^= k3 << 23;
//     k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
//     return (k2 + k4) % K + 1;
// }

// unsigned long long solve(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long n) {
//     setSeed(a, b, c);
//     unsigned long long res = xorShift128Plus();
//     for (a = 1; a != n; ++a) {
//         res = __gcd(res, xorShift128Plus());
//     }
//     return res;
// }

// int main() {
//     cout << 1 << endl;
//     return 0;
// }
#include<iostream>
using namespace std;
int solve(int n,int m)
{
    int i,sum;
    if(m==1) return 1;
    sum=0;
    for(i=1;i<n;i++)
       sum+= solve(i,m-1);
    return sum;
}
int main()
{
    int a = 11113, b = 149108;
    cout << (a ^ b) << endl;
}