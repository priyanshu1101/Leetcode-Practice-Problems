/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void parentRecordKeeper(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent){
        if(!root) return;
        if(root->left){
            parent[root->left]=root;
            parentRecordKeeper(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            parentRecordKeeper(root->right,parent);
        }
    }
    void infectedRecordKeeper(TreeNode* root,unordered_map<TreeNode*, bool> &infected,int first){
        if(!root) return;
        infected[root]=root->val==first;
        if(root->left){
            infectedRecordKeeper(root->left,infected,first);
        }
        if(root->right){
            infectedRecordKeeper(root->right,infected,first);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root->left && !root->right) return 0;
        unordered_map<TreeNode*, TreeNode*> parent;
        parentRecordKeeper(root, parent); // records
        unordered_map<TreeNode*, bool> infected;
        infectedRecordKeeper(root, infected, start);
        queue<TreeNode*> que;
        que.push(root);
        int time=0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* top = que.front();
                if (parent.find(top) != parent.end() && !infected[parent[top]]) {
                    que.push(parent[top]);
                    infected[parent[top]] = true;
                }
                if (top->left && !infected[top->left]) {
                    que.push(top->left);
                    infected[top->left] = true;
                }
                if (top->right && !infected[top->right]) {
                    que.push(top->right);
                    infected[top->right] = true;
                }
                que.pop();
            }
            time++;
        }
        return time;
    }
};