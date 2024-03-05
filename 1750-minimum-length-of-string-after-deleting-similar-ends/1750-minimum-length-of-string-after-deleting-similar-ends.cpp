class Solution {
public:
    int minimumLength(string s) {
        int pre=0,suf=s.length()-1;
        while(pre<suf){
            char last=s[suf];
            char first=s[pre];
            if(last!=first) return suf-pre+1;
            while(s[pre]==last && pre<suf) pre++;
            while(s[suf]==first && pre<suf) suf--;
        }
        if(pre==suf) return 0;
        return suf-pre+1;
    }
};