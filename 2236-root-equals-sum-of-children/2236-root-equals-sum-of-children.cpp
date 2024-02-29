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
    bool checkTree(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        int left=root->left==NULL? 0:root->left->val; 
        int right=root->right==NULL? 0:root->right->val;
        return (root->val==left+right) && checkTree(root->left) && checkTree(root->right);
    }
};