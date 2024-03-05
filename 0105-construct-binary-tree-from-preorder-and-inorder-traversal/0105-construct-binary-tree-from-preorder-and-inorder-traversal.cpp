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
    vector<int> leftSplit(vector<int> array,int target){
        vector<int> ans;
        for(int i=0;i<array.size();i++){
            if(array[i]!=target)
                ans.push_back(array[i]);
            else break;
        }
        return ans;
    }
    vector<int> rightSplit(vector<int> array,int target){
        vector<int> ans;
        int flag=0;
        for(int i=0;i<array.size();i++){
            if(flag==1)
                ans.push_back(array[i]);
            else if(array[i]==target)
                flag=1;
        }
        return ans;
    }
    vector<int> preorderSplit(vector<int> preorder,int skip,int size)
    {
        vector<int> ans;
        for(int i=0;i<preorder.size() && size!=0;i++)
        {
            if(skip!=0){
                skip--;
            }
            else{
                ans.push_back(preorder[i]);
                size--;
            }
        }
        return ans;
    }
    void buildTree(TreeNode* head,vector<int> preorder, vector<int> inorder){
        if(inorder.size()<=0) return;
        head->val=preorder[0];
        vector<int> leftInorder=leftSplit(inorder,head->val);
        vector<int> rightInorder=rightSplit(inorder,head->val);
        vector<int> leftPreorder=preorderSplit(preorder,1,leftInorder.size());
        vector<int> rightPreorder=preorderSplit(preorder,leftInorder.size()+1,rightInorder.size());
        if(leftInorder.size()!=0){
            head->left=new TreeNode(-1,NULL,NULL);
            buildTree(head->left,leftPreorder,leftInorder); 
        }
        if(rightInorder.size()!=0){
            head->right=new TreeNode(-1,NULL,NULL);
            buildTree(head->right,rightPreorder,rightInorder); 
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* head=new TreeNode(preorder[0],NULL,NULL);
        buildTree(head,preorder,inorder);
        return head;
    }
};