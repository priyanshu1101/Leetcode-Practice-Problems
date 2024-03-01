class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans="";
        int count=0;
        for(int i=0;i<s.length();i++)
            if(s[i]=='1') count++;
        count--;
        for(int i=0;i<s.length()-1;i++){
            if(count!=0){
                ans+='1';
                count--;
            }
            else
                ans+='0';
        }
        ans+='1';
        return ans;
    }
};