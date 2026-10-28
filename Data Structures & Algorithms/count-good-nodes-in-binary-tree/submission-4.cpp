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
    int dfs(TreeNode* root, int max) {
        if (!root) return 0;

        // found new good node
        int good = 0;
        if (root->val >= max) {
            max = root->val;
            good = 1;
        }
        max = std::max(max, root->val);
        
        return good + dfs(root->left, max) + dfs(root->right, max);
    }
    int goodNodes(TreeNode* root) {
        const auto ninf = numeric_limits<int>::min();
        
        return dfs(root, ninf);
    }
};
