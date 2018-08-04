/*
struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
                        val(x), next(NULL) {
        }
};*/
class Solution {
public:
    ListNode *insert(ListNode *head, ListNode *node) {
        node->next = head;
        return node;
    }
    ListNode *ReverseList(ListNode *pHead) {
        if (pHead == nullptr) {
            return pHead;
        }
        ListNode *new_head = nullptr;
        while (pHead) {
            auto node = pHead;
            pHead = pHead->next;
            new_head = insert(new_head, node);
        }
        return new_head;
    }
}; /*
 struct ListNode {
         int val;
         struct ListNode *next;
         ListNode(int x) :
                         val(x), next(NULL) {
         }
 };*/
class Solution {
public:
    ListNode *insert(ListNode *head, ListNode *node) {
        node->next = head;
        return node;
    }
    ListNode *ReverseList(ListNode *pHead) {
        /*
        struct ListNode {
                int val;
                struct ListNode *next;
                ListNode(int x) :
                                val(x), next(NULL) {
                }
        };*/
        class Solution {
        public:
            ListNode *insert(ListNode *head, ListNode *node) {
                node->next = head;
                return node;
            }
            ListNode *ReverseList(ListNode *pHead) {
                if (pHead == nullptr) {
                    return pHead;
                }
                ListNode *new_head = nullptr;
                while (pHead) {
                    auto node = pHead;
                    pHead = pHead->next;
                    new_head = insert(new_head, node);
                }
                return new_head;
            }
        }
    }
} /*
 struct ListNode {
         int val;
         struct ListNode *next;
         ListNode(int x) :
                         val(x), next(NULL) {
         }
 };*/
class Solution {
public:
    ListNode *insert(ListNode *head, ListNode *node) {
        node->next = head;
        return node;
    }
    ListNode *ReverseList(ListNode *pHead) {
