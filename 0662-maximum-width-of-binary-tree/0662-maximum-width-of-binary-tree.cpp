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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int ans=0;
        while(!q.empty()){
            int start,end;
            int size=q.size();
            int mmin=q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front().first;
                int curr=q.front().second;
                q.pop();
                if(i==0) start=curr;
                if(i==size-1) end=curr;
                if(temp->left) q.push({temp->left,(long long)(curr-mmin)*2+1});
                if(temp->right) q.push({temp->right,(long long)(curr-mmin)*2+2});
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};