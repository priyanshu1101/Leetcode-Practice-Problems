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
        void ansFetcher(TreeNode* root,map<pair<int,int>,vector<int>> &mp,int col,int row,int &minCol,int &maxCol)
        {
            if(!root) return;
            minCol=min(col,minCol);
            maxCol=max(col,maxCol);
            mp[{row,col}].push_back(root->val);
            ansFetcher(root->left,mp,col-1,row+1,minCol,maxCol);
            ansFetcher(root->right,mp,col+1,row+1,minCol,maxCol);
        }
        vector<vector<int>> verticalTraversal(TreeNode* root) {
           map<pair<int,int>,vector<int>> mp;
            int minCol=INT_MAX;
            int maxCol=INT_MIN;
            int col=0;
            int row=0;
            ansFetcher(root,mp,col,row,minCol,maxCol);
            minCol=abs(minCol);
            vector<vector<int>> ans(maxCol+minCol+1);
            for(auto itr=mp.begin();itr!=mp.end();itr++)
            {
                sort(itr->second.begin(),itr->second.end());
                int pos=itr->first.second+minCol;
                ans[pos].insert(ans[pos].end(),itr->second.begin(),itr->second.end());
            }
            return ans;
        }
    };