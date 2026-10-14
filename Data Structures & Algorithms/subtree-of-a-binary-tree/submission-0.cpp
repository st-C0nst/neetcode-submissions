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
    static bool same_tree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return p->val == q->val && same_tree(p->left, q->left) && same_tree(p->right, q->right);
    }
    
    static bool search_subtree(TreeNode* root, TreeNode* sub_root) {
        if (!root) return false;
        bool is_same = same_tree(root, sub_root);
        if (is_same) {
            return true;
        }

        bool in_left = search_subtree(root->left, sub_root);
        bool in_right = search_subtree(root->right, sub_root);
        return in_left || in_right;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return search_subtree(root, subRoot);
    }
};
