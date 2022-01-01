class Solution {
public:
    bool is_digit(char c) {
        return (c >= '0' && c <= '9');
    }
    bool is_left(char c) {
        return (c == '[');
    }
    bool is_right(char c) {
        return (c == ']');
    }
    string decodeString(string s) {
        int n = s.size();
        string res = "";

        for (int i = 0; i < n; ++i) {
            res += s[i];
            if (is_right(s[i])) {
                int j;
                for (j = i - 1; ~j; --j)
                    if (is_left(s[j])) break;
                string seg = res.substr(j + 1, i - j - 1);

                string num = "";
                for (j = j - 1; ~j; --j) {
                    if (!is_digit(s[j])) break;
                    num += s[j];
                }
                num = reverse(num.begin(), num.end());

                
            } 
        }
    }
};