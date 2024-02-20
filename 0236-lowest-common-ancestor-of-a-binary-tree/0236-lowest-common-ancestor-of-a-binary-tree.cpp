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
    bool ansFetcher(TreeNode* root,TreeNode* &ans,TreeNode* p, TreeNode* q)
    {
        if(!root) return false;
        bool left=ansFetcher(root->left,ans,p,q);
        bool right=ansFetcher(root->right,ans,p,q);
        if(((root->val==p->val || root->val==q->val) && left) || ((root->val==p->val || root->val==q->val) && right) || (left && right)){
            ans=root;
            return true;
        }
        if(root->val==p->val || root->val==q->val) return true;
        else return left|right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        ansFetcher(root,ans,p,q);
        return ans;
    }
};