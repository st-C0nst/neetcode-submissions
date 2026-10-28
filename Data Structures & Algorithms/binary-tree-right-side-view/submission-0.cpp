#include <print>
#include <unordered_set>
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
    using Set = std::unordered_set<int>;
    static void dfs(TreeNode* root, int level, vector<int>& rightmost, Set& visited) {
        if (root == nullptr) return;
        if (level + 1 > rightmost.size()) {
            rightmost.resize(level + 1);
        }
        
        // handle right
        dfs(root->right, level+1, rightmost, visited);
        
        // handle node
        // if first touch, add to list and mark visited
        if (!visited.contains(level)) {
            rightmost[level] = root->val;
            visited.insert(level);
        }

        // handle left
        dfs(root->left, level+1, rightmost, visited);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightmost;
        Set visited;
        dfs(root, 0, rightmost, visited);
        return rightmost;
    }
};

// one solution is we do a bfs and only read the right nodes
// this is not optimal tho
// can we dfs? I think we ca iterative dfs, can then track the right most seen for every level
// and if we do rnl and process node if flag unset, then we push it. 
// we cna mark in rightmost with inf, or have another array indicating visited/hashmap