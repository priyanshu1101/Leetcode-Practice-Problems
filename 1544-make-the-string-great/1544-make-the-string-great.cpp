class Solution {
public:
    string makeGood(string s) {
        string oldString;
        do{
            oldString=s;
            int length=s.length();
            for(int i=0;i<length-1;i++)
            {
                if( (islower(s[i])||islower(s[i+1])) && (isupper(s[i])||isupper(s[i+1])) && tolower(s[i])==tolower(s[i+1]))
                {
                    s=s.substr(0,i)+s.substr(i+2,s.length()-i-2);
                    break;
                }
            }
        }while(oldString!=s);
        return s;
    }
};