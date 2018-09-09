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
    int answer;
public:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        int arr_left = 0, arr_right = 0;
        if (root->left != NULL && root->left->val == root->val) {
            arr_left = left + 1;
        }

        if (root->right != NULL && root->right->val == root->val) {
            arr_right = right + 1;
        }

        answer = max(answer, arr_left + arr_right);
        return max(arr_left, arr_right);
    }

    int longestUnivaluePath(TreeNode* root) {
        answer = 0;
        dfs(root);
        return answer;
    }
};
