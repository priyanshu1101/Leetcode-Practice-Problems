class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        return s.substr(1,s.length()-1)+s.substr(0,1);
    }
};