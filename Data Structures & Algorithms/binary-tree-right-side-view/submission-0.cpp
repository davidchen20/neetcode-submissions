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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>();
        // check if the depth of the right subtree of parent is >= current && != current
        queue<TreeNode*> q;

        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* noi = q.front();
                q.pop();

                if (noi->left) q.push(noi->left);
                if (noi->right) q.push(noi->right);

                if (i == levelSize - 1) ans.push_back(noi->val);
            }
        }

        return ans;
    }
};
