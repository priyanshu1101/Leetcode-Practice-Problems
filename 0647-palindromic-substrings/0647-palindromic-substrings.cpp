class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                string temp=s.substr(i,j-i+1);
                string rev=temp;
                reverse(rev.begin(),rev.end());
                if(rev==temp) ans++;
            }
        }
        return ans;
    }
};