class Solution {
public:
    static bool comp(char a,char b){
        return a>b;
    }
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(),s.end(),comp);
        return s.substr(1,s.length()-1)+s.substr(0,1);
    }
};