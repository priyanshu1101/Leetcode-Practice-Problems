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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> subans(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
                if(flag)
                    subans[size-i-1]=node->val;
                else
                    subans[i]=node->val;
            }
            ans.push_back(subans);
            flag=!flag;
        }
        return ans;
    }
};