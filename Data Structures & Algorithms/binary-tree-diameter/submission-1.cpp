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
        // try every node as the center (find the max left and right subtree sums)
        if (!root) return 0;

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        int currentDiameter = heightOf(root->left) + heightOf(root->right);
        return max(currentDiameter, max(leftDiameter, rightDiameter));
    }

    int heightOf(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(heightOf(root->left), heightOf(root->right));
    }
};
