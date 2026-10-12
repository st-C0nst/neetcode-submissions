#include <print>
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

    using SumRes = std::pair<int,int>;
    static std::pair<int,int> add_nodes(ListNode* n1, ListNode* n2, const int prev_carry = 0) {
        if (!n1 && !n2) return {0, 0};
        int v1 = 0, v2 = 0;
        if (n1) {
            v1 = n1->val;
        }
        if (n2) {
            v2 = n2->val;
        }
        int sum = v1 + v2 + prev_carry;
        auto remainder = sum % 10;
        auto carry = sum / 10;
        return {remainder, carry};
    }

    static void push_back(ListNode*& head, ListNode*& tail, ListNode* node)  {
        if (!tail) {
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }
    
    static ListNode* add_numbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int curr_carry = 0;
        while (l1 || l2) {
            auto [sum, carry] = add_nodes(l1, l2, curr_carry);
            auto sum_node = new ListNode(sum);
            push_back(head, tail, sum_node);
            curr_carry = carry;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        
        if (curr_carry != 0) {
            push_back(head, tail, new ListNode(curr_carry));
        }
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add_numbers(l1, l2);
    }
};
