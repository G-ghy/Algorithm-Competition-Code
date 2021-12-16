/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //constexpr int N = 1e5 + 10;
    int depth[100010], f[100010][17];
    unordered_map<int, TreeNode*> mapping;

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        depth[0] = 0;
        depth[root->val] = 1;
        q.push(root);

        while (q.size()) {
            auto t = q.front(); q.pop();
            mapping[t->val] = t;
            TreeNode *p;
            p = t->left;
            if (p != nullptr) {
                q.push(p);
                depth[p->val] = depth[t->val] + 1;
                f[p->val][0] = t->val;
                for (int k = 1; k <= 16; ++k)
                    f[p->val][k] = f[f[p->val][k - 1]][k - 1];
            }
            p = t->right;
            if (p != nullptr) {
                q.push(p);
                depth[p->val] = depth[t->val] + 1;
                f[p->val][0] = t->val;
                for (int k = 1; k <= 16; ++k)
                    f[p->val][k] = f[f[p->val][k - 1]][k - 1];
            }
        }
    }
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b); // 保证a下b上
        for (int k = 16; ~k; -- k)
            if (depth[f[a][k]] >= depth[b]) // depth[0] = 0，决定了这里从a点出发不会跳转到b点之上
                a = f[a][k];
        if (a == b) return a;
        for (int k = 16; ~k; -- k)
            if (f[a][k] != f[b][k])
            {
                a = f[a][k];
                b = f[b][k];
            }
        return f[a][0];
    }
    string dfs(TreeNode *p, int d) {
        string path = "null";
        if (p->val == d) return "";
        bool flag = false;
        if (p->left != nullptr) {
            string ppath = dfs(p->left, d);
            if (ppath != "null") {
                flag = true;
                path = "L" + ppath;
            }
        }
        if (!flag && p->right != nullptr) {
            string ppath = dfs(p->right, d);
            if (ppath != "null") path = "R" + ppath;
        }
        return path;
    }
    string getDirections(TreeNode* root, int s, int d) {
        bfs(root);
        int p = lca(s, d);

        string res = "";
        if (s == p) {
            // string spath = dfs(root, s);
            // string dpath = dfs(root, d);
            // res = dpath.substr((int)spath.size());
            res = dfs(mapping[s], d);
        } else {
            for (int i = 0; i < depth[s] - depth[p]; ++i) res += "U";
            if (d != p) {
                // string ppath = dfs(root, p);
                // string dpath = dfs(root, d);
                // res += dpath.substr((int)ppath.size());
                res += dfs(mapping[p], d);
            }
        }

        return res;
    }
};