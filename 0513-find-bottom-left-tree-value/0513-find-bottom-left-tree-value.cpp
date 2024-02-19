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
    void ansFetcher(TreeNode* root,int height,int &maxHeight,int &ans)
    {
        if(!root) return;
        if(height>maxHeight){
            ans=root->val;
            maxHeight=height;
        };
        ansFetcher(root->left,height+1,maxHeight,ans);
        ansFetcher(root->right,height+1,maxHeight,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        int maxHeight=INT_MIN;
        ansFetcher(root,0,maxHeight,ans);
        return ans;
    }
};