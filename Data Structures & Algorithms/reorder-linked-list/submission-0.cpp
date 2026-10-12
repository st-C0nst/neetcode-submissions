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
    static ListNode* reverse_list(ListNode* head) {
        if (!head) return nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    static ListNode* split_list(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = nullptr;
        return head2;
    }

    static ListNode* pop_front(ListNode*& head){
        ListNode* node = head;
        head = head->next;
        node->next = nullptr;
        return node;
    }
    
    static ListNode* shuffle_merge(ListNode* l1, ListNode* l2) {
        ListNode* head = pop_front(l1);
        ListNode* curr = head;

        while (l1 && l2) {
            curr->next = pop_front(l2);
            curr = curr->next;
            
            curr->next = pop_front(l1);
            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
        }
        if (l2) {
            curr ->next = l2;
        }
        return head;
    }
    
    void reorderList(ListNode* head) {
        auto half = split_list(head);
        auto reversed_half = reverse_list(half);
        head = shuffle_merge(head, reversed_half);
    }
};
