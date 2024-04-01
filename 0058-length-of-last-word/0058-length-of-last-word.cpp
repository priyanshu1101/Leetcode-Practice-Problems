class Solution {
public:
    int lengthOfLastWord(string s) {
        int size=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' ' && size!=0) break;
            if(s[i]!=' ')
            {
                size++;
            }
        }
        return size;
    }
};