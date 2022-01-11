class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();

        int begin, pos = -1;
        while (1) {
            begin = pos + 1;
            pos = title.find(" ", begin);
            string str = title.substr(begin, pos - begin);
            if ((int)str.size() >= 3) {
                if (title[begin] >= 'a' && title[begin] <= 'z') title[begin] -= 32;
                for (int i = begin + 1; i < begin + (int)str.size(); ++i)
                    if (title[i] >= 'A' && title[i] <= 'Z') title[i] += 32;
            } else {
                for (int i = begin; i < begin + (int)str.size(); ++i)
                    if (title[i] >= 'A' && title[i] <= 'Z') title[i] += 32;
            }
            if (pos == -1) break;
        }
        
        return title;
    }
};