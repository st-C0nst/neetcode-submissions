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
    TreeNode* LCA(TreeNode* root, int lower, int upper) {
        if (root->val >= lower && root->val <= upper) return root;

        if (root->val < lower) {
            return LCA(root->right, lower, upper);
        }
        return LCA(root->left, lower, upper);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto lower = p->val;
        auto upper = q->val;
        if (lower> upper) {
            std::swap(lower, upper);
        }
        return LCA(root, lower, upper);
        
    }
};


// two solutions, one is merkle tree the other is a upper lower bound search
// we can compare to get the lower of p and q,
// lets say q is always larger

// for every node, compare against the p and q, and then update bounds
// if node v <= q && v >= p then we cant traverse further down, thus LCA
// 

// if v > q go left
// if v < p go right
