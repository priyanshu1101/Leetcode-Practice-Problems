class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        int minIndex=INT_MAX;
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]!=0)
                mp[s[i]]=INT_MAX;
            else
                mp[s[i]]=i+1;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            minIndex=min(minIndex,itr->second);
        }
        minIndex=minIndex==INT_MAX? -1:minIndex-1;
        return minIndex;
    }
};