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
    map<TreeNode*, TreeNode*> parent;
public:
    bool find_h(TreeNode* root, TreeNode* v, int& h) {
        if (!root) {
            return false;
        }

        if (root->val == v->val) {
            h = 0;
            return true;
        }

        if (root->left) {
            parent[root->left] = root;
        }

        if (root->right) {
            parent[root->right] = root;
        }

        int t;
        if (find_h(root->left, v, t)) {
            h = t + 1;
            return true;
        } else if (find_h(root->right, v, t)) {
            h = t + 1;
            return true;
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int hp, hq;
        find_h(root, p, hp);
        find_h(root, q, hq);
        //cout << hq << " " << hp << endl;
        while (hp != hq) {
            if (hp > hq) {
                p = parent[p];
                hp--;
            } else {
                q = parent[q];
                hq--;
            }
        }
        while (q !=p) {
            q = parent[q];
            p = parent[p];
        }
        return p;
    }
};
