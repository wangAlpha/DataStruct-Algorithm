/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode new_head(0);
        while (head != nullptr) {   
            auto p = &new_head;
            auto node = head;
            head = head->next;
            while (p->next != nullptr &&p->next->val < node->val) {
                p = p->next;
            }
            node->next = p->next;p->next = node;
            
        }
        return new_head.next;
    }
};
