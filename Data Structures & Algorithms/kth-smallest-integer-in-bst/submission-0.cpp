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
    int kthSmallest(TreeNode* root, int k) {
        // do an in order traversal and put everything in a vector
        // use k to index

        vector<int> inOrder;

        traverse(root, inOrder);

        // 1 -> 0, 
        int index = k - 1;
        return inOrder[index]; 
    }

    void traverse(TreeNode* root, vector<int>& inOrder) {
        if (!root) return;

        traverse(root->left, inOrder);
        inOrder.push_back(root->val);
        traverse(root->right, inOrder);
    }
};
