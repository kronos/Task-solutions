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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* r = NULL;
        if (t1 && t2) {
            r = new TreeNode(t1->val + t2->val);
            r->left = mergeTrees(t1->left, t2->left);
            r->right = mergeTrees(t1->right, t2->right);
        } else if (t1) {
            r = new TreeNode(t1->val);
            r->left = mergeTrees(t1->left, NULL);
            r->right = mergeTrees(t1->right, NULL);
        } else if (t2) {
            r = new TreeNode(t2->val);
            r->left = mergeTrees(NULL, t2->left);
            r->right = mergeTrees(NULL, t2->right);
        }

        return r;
    }
};
