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
    static ListNode* pop_front(ListNode*& head) {
        if (!head) {
            return nullptr;
        }
        auto node = head;
        head = head->next;
        node->next = nullptr;
        return node;
    }
    static ListNode* pop_min_node(ListNode*& l1, ListNode*& l2) {
        
        if (!l1 && !l2) {
            return nullptr;
        }
        if (!l1 || !l2) {
            return pop_front(l1 ? l1 : l2);
        }
        return pop_front(l1->val < l2->val ? l1 : l2);
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return nullptr;
        }
        if (!list1 || !list2) {
            return list1 ? list1 : list2;
        }

        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        auto node = pop_min_node(list1, list2);
        head = node;
        curr = node;
        
        while (list1 && list2) {
            auto node = pop_min_node(list1, list2);
            curr->next = node;
            curr = curr->next;
        }

        if (list1) {
            curr->next = list1;
        }
        if (list2) {
            curr->next = list2;
        }
        return head;
    }
};
