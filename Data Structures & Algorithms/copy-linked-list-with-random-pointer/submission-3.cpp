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
    struct OrgToCopyMap {
        public:
            Node* get_copy(Node* original) {
                if (!original) return nullptr;
                
                if (auto it = lookup_.find(original); it != lookup_.end()) {
                    return it->second;
                }
                
                return set_copy(original);
            }
            Node* set_copy(Node* original) {
                if (!original) return nullptr;
                
                auto copy = new Node(original->val);
                lookup_[original] = copy;
                return copy;
            }
            
        private:
            unordered_map<Node*, Node*> lookup_;
    };
    
    static Node* deep_copy_node(Node* original, OrgToCopyMap& copy_map) {
        auto copy = copy_map.get_copy(original);
        copy->next = copy_map.get_copy(original->next);
        copy->random = copy_map.get_copy(original->random);
        return copy;
    }
    
    static Node* deep_copy_list(Node* head) {
        OrgToCopyMap copy_map;
        auto copy_head = deep_copy_node(head, copy_map);
        
        auto curr = head->next;
        while (curr) {
            deep_copy_node(curr, copy_map);
            curr = curr->next;
        }
        
        return copy_head;
    }
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        return deep_copy_list(head);
    }
};
