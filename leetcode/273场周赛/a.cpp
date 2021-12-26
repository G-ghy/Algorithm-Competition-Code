class Solution {
public:
    string judgeZero(string num) {
        int pos;
        for (pos = 0; pos < num.size() - 1; ++pos)
            if (num[pos] != '0') break;

        return num.substr(pos);
    }
    bool isSameAfterReversals(int num) {
        string reversed = to_string(num);
        reverse(reversed.begin(), reversed.end());
        reversed = judgeZero(reversed);
        reverse(reversed.begin(), reversed.end());
        reversed = judgeZero(reversed);
        return reversed == to_string(num);
    }
};