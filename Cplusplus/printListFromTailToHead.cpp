/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    ListNode* insert(ListNode *head, ListNode *node) {
        node->next = head;
        return node;
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        if (head == nullptr) {
            return vec;
        }
        ListNode *new_head = nullptr;
        while (head) {
            auto node = head;
            head = head->next;
            new_head = insert(new_head, node);
        }
        while(new_head != nullptr) {
            vec.push_back(new_head->val);
            new_head = new_head->next;
        }
        return vec;
    }
};