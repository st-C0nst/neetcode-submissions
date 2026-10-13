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
    int maxDepth(TreeNode* root) {
        return find_depth(root);
    }

    int find_depth(TreeNode* root) {
        if (!root) return 0;
        int left_depth = find_depth(root->left);
        int right_depth = find_depth(root->right);

        return  1 + max(left_depth, right_depth);
    }
};
