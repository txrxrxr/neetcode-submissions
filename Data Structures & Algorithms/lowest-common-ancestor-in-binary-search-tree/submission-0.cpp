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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // find the first node where p and q are on the 2 sides
        // or the first node == p or == q
        return dfs(root, p ,q);
    }

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) {
            return root;
        }
        int min = std::min(p->val, q->val);
        int max = std::max(p->val, q->val);
        if (root->val > min && root->val < max) {
            return root;
        } else if (root->val > max) {
            return dfs(root->left, p, q);
        } else {
            return dfs(root->right, p, q);
        }
    }

};
