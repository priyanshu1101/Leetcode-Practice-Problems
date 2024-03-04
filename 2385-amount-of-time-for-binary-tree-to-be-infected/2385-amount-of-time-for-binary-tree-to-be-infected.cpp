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
    unordered_map<TreeNode*,TreeNode*> parent_path;
    void parentRecordKeeper(TreeNode* root){
        if(!root) return;
        if(root->left) parent_path[root->left]=root;
        if(root->right) parent_path[root->right]=root;
        parentRecordKeeper(root->left);
        parentRecordKeeper(root->right);
    }
    TreeNode* findTarget(TreeNode* root,int start){
        if(!root) return NULL;
        if(root->val==start) return root;
        TreeNode* temp=findTarget(root->left,start);
        return temp==NULL? findTarget(root->right,start):temp;
    }
    int amountOfTime(TreeNode* root, int start) {
        parentRecordKeeper(root);
        TreeNode* target=findTarget(root,start);
        queue<TreeNode*> que;
        unordered_map<TreeNode*,bool> infected;
        int timeCount=0;
        que.push(target);
        infected[target]=true;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* temp=que.front();
                que.pop();
                if(temp->left && !infected[temp->left]){
                    que.push(temp->left);
                    infected[temp->left]=true;
                }
                if(temp->right && !infected[temp->right]){
                    que.push(temp->right);
                    infected[temp->right]=true;
                }
                if(parent_path[temp] && !infected[parent_path[temp]]){
                    que.push(parent_path[temp]);
                    infected[parent_path[temp]]=true;
                }
            }
            timeCount++;
        }
        return --timeCount;
    }
};