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
    int maxFinder(TreeNode* root,int &maxPath)
    {
        if(!root)   return 0;
        int leftValue=(maxFinder(root->left,maxPath)<0)? 0:maxFinder(root->left,maxPath);
        int rightValue=(maxFinder(root->right,maxPath)<0)? 0:maxFinder(root->right,maxPath);
        maxPath=max(maxPath,leftValue+root->val+rightValue);
        return max(leftValue,rightValue)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxPath=INT_MIN;
        int valueIncludingRoot=maxFinder(root,maxPath);
        return max(maxPath,valueIncludingRoot);
    }
};