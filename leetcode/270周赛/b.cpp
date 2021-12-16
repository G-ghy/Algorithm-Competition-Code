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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *dummyHead(0, head);
        ListNode *p = head;

        int len = 0;
        for (; p != nullptr; p = p->next) ++len;

        p = head;
        for (int i = 0; i < len - 1; ++i) p = p->next;

        if (p->next == nullptr) p->next = p->next->next;
        else head = nullptr;
        
        return head;
    }
};