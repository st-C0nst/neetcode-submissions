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
    int max_diameter{};
    int find_depth(TreeNode* root) {
        if (!root) return 0;
        auto left_depth = find_depth(root->left);
        auto right_depth = find_depth(root->right);
        int curr_diameter = left_depth + right_depth;
        max_diameter = max(curr_diameter, max_diameter);

        return 1 + max(left_depth, right_depth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        find_depth(root);
        return max_diameter;
    }
};
