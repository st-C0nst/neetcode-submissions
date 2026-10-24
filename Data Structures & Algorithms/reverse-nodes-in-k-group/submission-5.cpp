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
    ListNode* reverse_list(ListNode* head, ListNode* end = nullptr) {
        if (!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto curr = head;
        for (int i = 0; i < k; ++i) {
            // if we dont have k nodes, return remainder
            if (!curr) return head;
            curr = curr->next;
        }
        auto new_tail = head;
        auto remainder_head = curr;
        // curr points to next head now
        auto rev_head = reverse_list(head, remainder_head);
        // head is now the new tail, curr is the remaining list
        new_tail->next = reverseKGroup(curr, k);
        
        return rev_head;
    }
};
