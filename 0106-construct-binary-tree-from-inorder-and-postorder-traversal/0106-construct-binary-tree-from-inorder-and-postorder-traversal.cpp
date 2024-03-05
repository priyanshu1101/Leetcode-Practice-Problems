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
    void inorderSplit(vector<int> array,int target,vector<int> &leftInorder,vector<int> &rightInorder)
    {
        int flag=0;
        for(int i=0;i<array.size();i++){
            if(target!=array[i] && flag==0){
                leftInorder.push_back(array[i]);
            }
            else if(target==array[i]) flag=1;
            else
                rightInorder.push_back(array[i]);
        }
    }
    void postOrderSplit(vector<int> array,vector<int> &leftPostorder,vector<int> &rightPostorder,vector<int> &leftInorder,vector<int> &rightInorder){
        for(int i=0;i<leftInorder.size();i++)
            leftPostorder.push_back(array[i]);
        for(int i=leftInorder.size();i<leftInorder.size()+rightInorder.size();i++)
            rightPostorder.push_back(array[i]);
    }
    void buildNewTree(TreeNode* head,vector<int>& inorder, vector<int>& postorder)
    {
        if(postorder.size()==0) return;
        head->val=postorder[postorder.size()-1];
        vector<int> leftInorder;
        vector<int> rightInorder;
        vector<int> leftPostorder;
        vector<int> rightPostorder;
        inorderSplit(inorder,head->val,leftInorder,rightInorder);
        postOrderSplit(postorder,leftPostorder,rightPostorder,leftInorder,rightInorder);
        if(leftInorder.size()!=0){
            head->left=new TreeNode(head->val,NULL,NULL);
            buildNewTree(head->left,leftInorder,leftPostorder);
        }
        if(rightInorder.size()!=0){
            head->right=new TreeNode(head->val,NULL,NULL);
            buildNewTree(head->right,rightInorder,rightPostorder);
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* head= new TreeNode(-1,NULL,NULL);
        buildNewTree(head,inorder,postorder);
        return head;
    }
};