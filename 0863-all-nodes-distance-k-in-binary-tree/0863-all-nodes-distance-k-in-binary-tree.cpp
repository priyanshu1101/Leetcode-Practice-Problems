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
    void traversal(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &record){
        if(!root) return;
        if(root->left) record[root->left]=root;
        if(root->right) record[root->right]=root;
        traversal(root->left,record);
        traversal(root->right,record);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> record;
        traversal(root,record);
        queue<TreeNode*> que;
        unordered_map<TreeNode*,bool> visited;
        que.push(target);
        int level=0;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* temp=que.front();
                que.pop();
                visited[temp]=true;
                if(level==k) ans.push_back(temp->val);
                if(record.find(temp)!=record.end() && !visited[record[temp]]){
                    que.push(record[temp]);
                }
                if(temp->left && !visited[temp->left]){
                    que.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    que.push(temp->right);
                    visited[temp->right]=true;
                }
            }
            level++;
        }
        return ans;
    }
};