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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;

        TreeNode* leftChild = invertTree(root->left);
        TreeNode* rightChild = invertTree(root->right);

        TreeNode* temp = leftChild;
        root->left = rightChild;
        root->right = temp;

        return root;
    }
};
