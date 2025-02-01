class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        for(int i=0;i<=rowIndex-1;i++)
        {
            ans.push_back(1);
            for(int j=i;j>=1;j--)
            {
                ans[j]=ans[j]+ans[j-1];
            }
        }
        return ans;
    }
};