        ansFetcher(root->right,height+1,maxHeight,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxHeight=INT_MIN;
        ansFetcher(root,0,maxHeight,ans);
        return ans;
            maxHeight=height;
            ans.push_back(root->val);
        }
    void ansFetcher(TreeNode* root,int height,int &maxHeight,vector<int> &ans)
    {
        if(!root) return;
        if(height>maxHeight){
        ansFetcher(root->left,height+1,maxHeight,ans);
    }
[
