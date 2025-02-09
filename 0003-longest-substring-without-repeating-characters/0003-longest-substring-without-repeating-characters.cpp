class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int ans=0;
        int curr=0;
        int starting=1;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=starting)// exist
            {
                starting=mp[s[i]]+1;
                curr=i+1-mp[s[i]];
                mp[s[i]]=i+1;
            }
            else{
                curr++;
                mp[s[i]]=i+1;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};