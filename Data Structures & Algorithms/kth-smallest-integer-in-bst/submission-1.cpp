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
        vector<int> order;
        traverse(root, order);

        return order[k-1];
    }

    void traverse(TreeNode* root, vector<int>& order) {
        if (!root) return;

        traverse(root->left, order);
        order.push_back(root->val);
        traverse(root->right, order);
    }
};
