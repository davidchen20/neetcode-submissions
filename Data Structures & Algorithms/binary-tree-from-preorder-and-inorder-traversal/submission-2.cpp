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
        // get order from preorder
        // check whats left and whats right from inorder

        unordered_map<int, int> m;

        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }   

        int idx = 0;
        return buildSubtree(preorder, m, idx, 0, preorder.size()-1);
    }

    TreeNode* buildSubtree(vector<int>& preorder, unordered_map<int, int>& m, int& idx, int left, int right) {
        if (left > right) return nullptr;
        
        int rootVal = preorder[idx++];
        TreeNode* node = new TreeNode(rootVal);

        int mid = m[rootVal];

        node->left = buildSubtree(preorder, m, idx, left, mid-1);
        node->right = buildSubtree(preorder, m, idx, mid+1, right);

        return node;
        // if left > right then return nullptr

        // create node
        // make left subtree
        // make right subtree
    }
};
