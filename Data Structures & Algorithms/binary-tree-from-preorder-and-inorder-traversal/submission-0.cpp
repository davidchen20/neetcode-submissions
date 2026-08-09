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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }

        int idx = 0;

        return buildSubtree(preorder, idx, m, 0, preorder.size() - 1);
    }

    TreeNode* buildSubtree(vector<int>& preorder, int& idx, unordered_map<int, int>& m, int left, int right) {
        if (left > right) return nullptr;

        TreeNode* node = new TreeNode(preorder[idx++]);
        // build the current node,

        // build left subtree
        node->left = buildSubtree(preorder, idx, m, left, m[node->val] - 1);
        node->right = buildSubtree(preorder, idx, m, m[node->val] + 1 , right);
        // build right subtree

        return node;
    }
};
