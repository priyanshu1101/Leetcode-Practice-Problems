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
    int ans=INT_MIN;
    int ansFetcher(TreeNode* root){
        if(!root) return 0;
        int left=ansFetcher(root->left);
        int right=ansFetcher(root->right);
        int val=(left<0? 0:left)+(right<0? 0:right)+root->val;
        ans=max(ans,val);
        return root->val+max(left,max(right,0));
    }
    int maxPathSum(TreeNode* root) {
        return max(ansFetcher(root),ans);
    }
};