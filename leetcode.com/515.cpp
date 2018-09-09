/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    void rec(TreeNode* root, int level, vector<int>& ans) {
        if (root) {
            if (ans.size() <= level) {
                ans.push_back(root->val);
            } else {
                ans[level] = max(ans[level], root->val);
            }

            rec(root->left, level+1, ans);
            rec(root->right, level+1, ans);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        rec(root, 0, ans);
        return ans;
    }
};
