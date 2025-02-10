class Solution {
public:
    bool isDigit(char ch){
        return int(ch)>=48 && int(ch)<=57;
    }
    bool isChar(char ch){
        return !isDigit(ch);
    }
    string clearDigits(string s) {
        int i=0;
        while(i!=s.length()){
            if(isDigit(s[i])){
                if(i!=0){
                    s=s.substr(0,i-1)+s.substr(i+1,s.length()-i-1);
                    i=0;
                }
                else i++;
            }
            else i++;
        }
        return s;
    }
};