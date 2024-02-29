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
    bool isEvenOddTree(TreeNode* root) {
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int lastMin=INT_MAX;
            int lastMax=INT_MIN;
            for(int i=0;i<size;i++){
                if(level%2==0){
                    TreeNode* temp=q.front();
                    q.pop();
                    if(temp->val%2==0 || lastMax>=temp->val)  return false;
                    lastMax=temp->val;
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                else{
                    TreeNode* temp=q.front();
                    q.pop();
                    if(temp->val%2!=0 || lastMin<=temp->val)  return false;
                    lastMin=temp->val;
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
            level++;
        }
        return true;
    }
};