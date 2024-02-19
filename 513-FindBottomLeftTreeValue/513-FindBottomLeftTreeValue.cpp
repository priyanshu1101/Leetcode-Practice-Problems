            ans=root->val;
            maxHeight=height;
        };
        ansFetcher(root->left,height+1,maxHeight,ans);
        ansFetcher(root->right,height+1,maxHeight,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        int maxHeight=INT_MIN;
        ansFetcher(root,0,maxHeight,ans);
        return ans;
    }
};
[2,1,3]
