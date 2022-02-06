class Solution {
public:
    int get(int st, int mc, int pc, int min, int sec) {
        int cnt = 0;
        int b[4] = {min / 10, min % 10, sec / 10, sec % 10};
        
        int i;
        for (i = 0; i < 4; ++i)
            if (b[i]) break;
        for (; i < 4; ++i)
           if (st != b[i]) {
                cnt += mc + pc;
                st = b[i];
            } else {
                cnt += pc;
            }
        
        return cnt;
    }
    int minCostSetTime(int st, int mc, int pc, int ts) {
        int res = 2147483647;
        int min = (ts / 60 > 99) ? 99 : ts / 60; // 被卡两次
        for (; ~min && ts - min * 60 <= 99; --min) {
            int sec = ts - min * 60;
            int cnt = get(st, mc, pc, min, sec);
            if (cnt < res) res = cnt;
        }

        return res;
    }
};