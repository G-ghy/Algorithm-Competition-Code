class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> rela;
        unordered_map<string, int> in;
        unordered_set<string> st;
        
        for (string sub : supplies ) {
            if(!rela.count("begin")) rela["begin"] = vector<string>();
            rela["begin"].push_back(sub);
            if (!in.count(sub)) in[sub] = 0;
            ++in[sub];
        }

        for (int i = 0; i < ingredients.size(); ++i) {
            for (string ingr : ingredients[i]) {
                if (!rela.count(ingr)) rela[ingr] = vector<string>();
                rela[ingr].push_back(recipes[i]);
                if (!in.count(recipes[i])) in[recipes[i]] = 0;
                ++in[recipes[i]];
            }
        }
        
        for (string reci : recipes)
            if (!st.count(reci)) st.insert(reci);
        
        vector<string> res;
        queue<string> q;
        q.push("begin");
        while (q.size()) {
            string point = q.front(); q.pop();
            if (st.count(point)) res.push_back(point);

            for (string nextPoint : rela[point]) {
                --in[nextPoint];
                if (!in[nextPoint]) q.push(nextPoint);
            }
        }
        
        return res;
    }
};