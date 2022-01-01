/** 以下的高位和低位都是对应存储结构中的高位和低位的概念
 *  数字: 123，从左到右，高位到低位
 *  字符串: "123" 从左到右，低位到高位
 *  数组: [3, 2, 1] 从左到右，低位到高位
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cnt;

bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; -- i) //注意是从数字的高位开始比较，数字的高位存储在数组的高位
        if (A[i] != B[i]) return A[i] > B[i];
    return true;
}
vector<int> sub(vector<int> &A, vector<int> &B)
{
    int t = 0;
    vector<int> C;
    for (int i = 0; i < A.size(); ++ i)
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        // 在次之前，t的含义是i位的运算结果，在次之后，t的含义是i+1位的借位值
        if (t < 0) {
            t = 1;
            ++cnt;
        }
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 处理前导0
    return C;
}
int main()
{
    string a, b;
    vector<int> A, B;
    
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; -- i) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; -- i) B.push_back(b[i] - '0');
    
    vector<int> C;
    if (!cmp(A, B)) 
    {
        // cout << '-';
        C = sub(B, A);
    }
    else C = sub(A, B);

    cout << cnt << '\n';

    return 0;
}
