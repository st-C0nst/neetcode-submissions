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
    using Wv = std::queue<TreeNode*>;
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        Wv wv;
        wv.push(root);
        std::vector<int> res;

        while (!wv.empty()) {
            int level_size = wv.size();
            
            for (int i = 0; i < level_size; ++i) {
                auto top = wv.front();
                wv.pop();

                if (i == level_size - 1) {
                    res.push_back(top->val);
                }
                
                if (top->left) {
                    wv.push(top->left);
                }
                if (top->right) {
                    wv.push(top->right);
                }
            }
        }
        return res;
    }
};

// lets solve it the bfs way.