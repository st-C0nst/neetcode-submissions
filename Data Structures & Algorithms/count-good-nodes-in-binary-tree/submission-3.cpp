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
    void dfs(TreeNode* root, int max, int& count) {
        if (!root) return;

        // found new good node
        if (root->val >= max) {
            max = root->val;
            ++count;
        }
        
        dfs(root->left, max, count);
        dfs(root->right, max, count);
    }
    int goodNodes(TreeNode* root) {
        const auto ninf = numeric_limits<int>::min();
        int count{};
        dfs(root, ninf, count);
        return count;
    }
};
