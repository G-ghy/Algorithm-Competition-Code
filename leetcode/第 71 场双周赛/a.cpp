class Solution {
public:
    int minimumSum(int num) {
        int a[4];
        for (int i = 0; i < 4; ++i) {
            a[i] = num % 10;
            num /= 10;
        }
        sort(a, a + 4);
        int n1 = a[0] * 10 + a[2];
        int n2 = a[1] * 10 + a[3];
        return n1 + n2;
    }
};