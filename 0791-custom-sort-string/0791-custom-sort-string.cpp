class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i+1;
        }

        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length()-i-1;j++){
                int value1=mp[s[j]]==0? INT_MAX:mp[s[j]];
                int value2=mp[s[j+1]]==0? INT_MAX:mp[s[j+1]];
                if(value1>value2)
                    swap(s[j],s[j+1]);
            }
        }
        return s;
    }
};