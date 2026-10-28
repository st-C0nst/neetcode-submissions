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
    bool is_valid_BST(TreeNode* root, int upper, int lower) {
        if (!root) return true;
        if (root->val >= upper || root->val <= lower) return false;

        return is_valid_BST(root->left, root->val, lower) && is_valid_BST(root->right, upper, root->val);
    }
    bool isValidBST(TreeNode* root) {
        const auto ninf = numeric_limits<int>::min();
        const auto inf = numeric_limits<int>::max();
        return is_valid_BST(root, inf, ninf);
    }
};
