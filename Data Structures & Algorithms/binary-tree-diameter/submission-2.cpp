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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int currentDiameter = helper(root->left) + helper(root->right);
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        
        return max(currentDiameter, max(right, left));
    }

    int helper(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(helper(root->left), helper(root->right));
    }
};
