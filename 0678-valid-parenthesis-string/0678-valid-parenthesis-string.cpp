class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star;
        int open=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*') star.push(i);
            else if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                if(open==0 && star.size()==0) return false;
                else if(open!=0) open--;
                else {
                    s[star.top()]='(';
                    star.pop();
                }
            }
        }
        while(!star.empty()) star.pop();
        int close=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='*') star.push(i);
            else if(s[i]==')'){
                close++;
            }
            else if(s[i]=='('){
                if(close==0 && star.size()==0) return false;
                else if(close!=0) close--;
                else {
                    s[star.top()]=')';
                    star.pop();
                }
            }
        }
        return true;
    }
};