class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(mp.find(temp)==mp.end())
            { 
                mp[temp]={strs[i]};
            }
            else
                mp[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            ans.push_back(itr->second);
        }
        return ans;
    }
};