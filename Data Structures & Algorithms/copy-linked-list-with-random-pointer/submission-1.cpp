#include <unordered_map>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    using OrgToCopy = unordered_map<Node*, Node*>;
    [[nodiscard]]
    static OrgToCopy create_list_copy(Node* head) {
        if (!head) return {};
        OrgToCopy copy_map;
        
        auto copy_head = new Node(head->val);
        
        copy_map[head] = copy_head;
        auto curr = head->next;
        auto prev_cpy = copy_head;
        
        while (curr) {
            Node* copy = new Node(curr->val);
            copy_map[curr] = copy;
            
            prev_cpy->next = copy;
            prev_cpy = copy;
            
            curr = curr->next;
        }
        return copy_map;
    }

    static Node* set_random_ptrs(Node* head, OrgToCopy& copy_map) {
        auto copy_head = copy_map[head];

        auto curr = head;
        auto copy_curr = copy_head;

        while (curr) {
            auto rand_copy = copy_map[curr->random];
            copy_curr->random = rand_copy;
            
            curr = curr->next;
            copy_curr = copy_curr->next;
        }
        
        return copy_head;
    }
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        auto copy_map = create_list_copy(head);
        return set_random_ptrs(head, copy_map);
    }
};
