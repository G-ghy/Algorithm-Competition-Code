/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;

        ListNode* p = head;
        while (p != nullptr) {
            vec.push_back(p->val);
            p = p->next;   
        }

        int res = -0x3f3f3f3f;
        for (int i = 0; i < (int)vec.size(); ++i) {
            res = max(res, vec[i] + vec[(int)vec.size() - i - 1]);
        }

        return res;
    }
};