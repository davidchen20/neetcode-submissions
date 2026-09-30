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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return helper(root, root->val);
    }

    int helper(TreeNode* root, int maxSoFar) {
        if (!root) return 0;

        if (root->val >= maxSoFar) return 1 + helper(root->left, root->val) + helper(root->right, root->val);

        return helper(root->left, maxSoFar) + helper(root->right, maxSoFar); 
    }
};
