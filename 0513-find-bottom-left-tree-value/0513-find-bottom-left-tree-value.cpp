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
    int maxHeight;
    int ans;
    void solve(TreeNode* root,int height){
        if(!root) return;
        if(maxHeight<height){
            maxHeight=height;
            ans=root->val;
        }
        solve(root->left,height+1);
        solve(root->right,height+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        maxHeight=INT_MIN;
        solve(root,0);
        return ans;
    }
};