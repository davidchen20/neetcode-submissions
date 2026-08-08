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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        queue<TreeNode*> q;

        vector<vector<int>> ans;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            vector<int> level;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* noi = q.front();
                q.pop();
                level.push_back(noi->val);
                if (noi->left) q.push(noi->left);
                if (noi->right) q.push(noi->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
