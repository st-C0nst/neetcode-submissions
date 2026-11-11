/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    using NodeMap = std::vector<Node*>;
        
    Node* get_clone(Node* node, NodeMap& clones_) {
        if (node == nullptr) return nullptr;
        // find clone for our node
        if (auto cres = clones_[node->val]; cres != nullptr) {
            return cres;
        }
        std::vector<Node*> clone_neigh;
        clone_neigh.reserve(node->neighbors.size());
        clones_[node->val] = new Node(node->val);
        
        for (const auto& n : node->neighbors) {
            clone_neigh.push_back(get_clone(n, clones_));
        }

        clones_[node->val]->neighbors = std::move(clone_neigh);
        return clones_[node->val];
    }
    Node* cloneGraph(Node* node) {
        NodeMap clones(101);
        return get_clone(node, clones);
        
    }
};

// grab clone, if it doesnt exist, make clone and create mapping
