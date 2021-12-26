class Solution {
public:
    int mostWordsFound(vector<string>& ss) {
        int maxWord = -0x3f3f3f3f;
        for (string str : ss) {
            int res = 0;
            while (1) {
                string t = str.substr(0, (int)str.find(" "));
                string subS = str.substr((int)str.find(" ") + 1);
                ++res;
                if (subS == str) break;
                str = subS;
            }
            maxWord = max(maxWord, res);
        }

        return maxWord;
    }
};