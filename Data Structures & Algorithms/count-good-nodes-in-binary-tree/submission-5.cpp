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
    struct Entry {
        TreeNode* node;
        int max_seen;
    };
    using Wavefront = queue<Entry>;
    int goodNodes(TreeNode* root) {
        int num_good = 1;
        Wavefront wv;
        wv.push({root, root->val});

        while (!wv.empty()) {
            int width = wv.size();
            for (int i = 0; i < width; ++i) {
                auto curr = std::move(wv.front());
                wv.pop();

                auto left = curr.node->left;
                if (left) {
                    if (left->val >= curr.max_seen) {
                        ++num_good;
                    }
                    wv.push({left, max(left->val, curr.max_seen)});
                }
                auto right = curr.node->right;
                if (right) {
                    if (right->val >= curr.max_seen) {
                        ++num_good;
                    }
                    wv.push({right, max(right->val, curr.max_seen)});
                }
            }
        }

        return num_good;
    }
};

// lets solve with bfs
// every node can store its max seen