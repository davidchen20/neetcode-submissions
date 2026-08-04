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
        else {
            int childrenDiameters = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
            int nodeDiameter = heightOf(root->left) + heightOf(root->right);

            return max(childrenDiameters, nodeDiameter);
        }
    }

    int heightOf(TreeNode* root) {
        if (!root) return 0;

        return max(heightOf(root->left), heightOf(root->right)) + 1;
    }

    
};
