#include <unordered_set>
#include <print>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    struct StackEntry {
    TreeNode* node;
  int level;
    };
    using Stack = std::vector<StackEntry>;
    using Set = std::unordered_set<int>;
    
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        Stack call_stack;
        vector<int> res;
        Set visited;
        StackEntry curr{root, 0};
        call_stack.push_back(curr);
        std::println("pushing root {}", root->val);

        while(!call_stack.empty()) {
            while (curr.node && curr.node->right) {
                ++curr.level;
                curr.node = curr.node->right;
                call_stack.push_back(curr);
            }
            
            // process node
            curr = std::move(call_stack.back());
            call_stack.pop_back();
            
            if (curr.level + 1 > res.size()) {
                res.resize(curr.level + 1);
            }

            if (!visited.contains(curr.level)) {
                res[curr.level] = curr.node->val;
                visited.insert(curr.level);
            }


            // add left
            curr.node = curr.node->left;
            ++curr.level;
            if (curr.node) {
                call_stack.push_back(curr);
            }
        }
        return res;
    }
};

// lets solve it the iterative dfs solution