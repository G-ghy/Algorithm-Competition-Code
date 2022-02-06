class Solution {
public:
    long long smallestNumber(long long num) {
        int neg = 1;
        if (num < 0) {
            neg = -1;
            num = -num;
        }

        vector<char> sub;
        string str = to_string(num);
        for (char c : str) sub.push_back(c);
        if (neg == -1) sort(sub.begin(), sub.end(), [](char a, char b) -> bool {return a > b;});
        else sort(sub.begin(), sub.end());
        
        if (num == 0) return 0;
        else {
            int pos = 0;
            while (pos < (int)sub.size()) {
                if (sub[pos] != '0') break;
                ++pos;
            }

            string res = "";
            res += sub[pos];
            for (int i = 0; i < (int)sub.size(); ++i)
                if (i != pos) res += sub[i];
            
            return atoll(res.c_str()) * neg;
        }
        
        return 0;
    }
};