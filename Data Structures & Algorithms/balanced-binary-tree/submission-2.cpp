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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        if (!isBalanced(root->left) || !isBalanced(root->right)) return false;

        int leftHeight = heightOf(root->left);
        int rightHeight = heightOf(root->right);

        return abs(leftHeight - rightHeight) <= 1;
    }

    int heightOf(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(heightOf(root->left), heightOf(root->right));
    }
};
