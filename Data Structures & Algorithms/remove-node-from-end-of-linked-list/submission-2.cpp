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
    static ListNode* detach_node(ListNode* prev) {
        if (!prev) return nullptr;
        if (!prev->next) return nullptr;

        ListNode* node = prev->next;

        prev->next = node->next;
        node->next = nullptr;
        
        return node;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* back = head;
        for (int space = 0; space < n + 1; ++space) {
            if (!back) {
                auto prev = head;
                head = head->next;
                
                prev->next = nullptr;
                return head;
            }
            back = back->next;
        }

        ListNode* curr = head;
        while (back) {
            curr = curr->next;
            back = back->next;
        }

        std::ignore = detach_node(curr);
        
        return head;
    }
};
