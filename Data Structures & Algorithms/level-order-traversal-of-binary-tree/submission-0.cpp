#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;

        queue<TreeNode*> wv;
        wv.push(root);
        while (!wv.empty()) {
            int level_size = wv.size();
            vector<int> level;
            level.reserve(level_size);
            //
            for (int i = 0; i < level_size; ++i) {
                auto curr = wv.front();
                wv.pop();

                level.push_back(curr->val);

                if (curr->left) {
                    wv.push(curr->left);
                }
                if (curr->right) {
                    wv.push(curr->right);
                }
            }

            res.push_back(std::move(level));
        }
    return res;
    }
};
