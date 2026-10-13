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
#include <cmath>
#include <utility>

class Solution {
public:
    using BalanceRes = std::pair<bool, size_t>;
    static BalanceRes is_balanced(TreeNode* root) {
        if (!root) return {true, 0};
        
        auto [is_left_balanced, left_depth] = is_balanced(root->left);
        auto [is_right_balanced, right_depth] = is_balanced(root->right);

        if (!is_left_balanced || !is_right_balanced) {
            return {false, 0};
        }

        bool balanced = (std::abs(static_cast<int>(left_depth) - static_cast<int>(right_depth)) <= 1);
        return {balanced, 1 + std::max(left_depth, right_depth)};
    }
    
    bool isBalanced(TreeNode* root) {
        auto [balanced, _] = is_balanced(root);
        return balanced;
    }
};
