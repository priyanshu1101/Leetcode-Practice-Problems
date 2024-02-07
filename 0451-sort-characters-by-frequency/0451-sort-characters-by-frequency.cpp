class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        vector<pair<int,char>> record;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            record.push_back({itr->second,itr->first});
        }
        sort(record.begin(),record.end());
        for(int i=0;i<record.size();i++)
        {
            for(int j=0;j<record[i].first;j++)
                ans+=record[i].second;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};