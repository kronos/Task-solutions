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
   // set<int> visited;
public:
    bool check(TreeNode* root, long long mmin, long long mmax) {
        if (!root) {
            return true;
        }
        if (root->val <= mmin || root->val >= mmax) {
            return false;
        }

        return check(root->left, mmin, root->val) && check(root->right, root->val, mmax);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }
};
