class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        for(int i=0;i<s1.length();i++){
            for(int j=i;j<s1.length();j++){
                swap(s1[i],s1[j]);
                if(s1==s2) return true;
                swap(s1[i],s1[j]);
            }
        }
        return false;
    }
};