constexpr int N = 6e5 + 10;

class Solution {
public:
    int son[N][26], idx = 0;
    int cnt[N];
    void insert(string &str)
    {
        int p = 0;
        for (int i = 0; str[i]; i ++)
        {
            int u = str[i] - 'a';
            if (!son[p][u]) son[p][u] = ++ idx;
            p = son[p][u];
        }
        cnt[p] ++ ;
    }
    int query(string &str)
    {
        int p = 0;
        for (int i = 0; str[i]; i ++ )
        {
            int u = str[i] - 'a';
            if (!son[p][u]) return 0;
            p = son[p][u];
        }
        return cnt[p];
    }
    int wordCount(vector<string>& sW, vector<string>& tW) {
        for (string word : sW) {
            sort(word.begin(), word.end());
            insert(word);
        }
        
        int cnt = 0;
        for (string word : tW) {
            int n = word.size();
            sort(word.begin(), word.end());

            for (int i = 0; i < n; ++i) {
                string t = word.substr(0, i) + word.substr(i + 1);
                if (query(t)) {
                    ++cnt;
                    break;
                }
            }
        }

        return cnt;
    }
};