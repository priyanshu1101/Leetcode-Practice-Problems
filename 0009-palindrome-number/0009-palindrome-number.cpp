class Solution {
public:
    bool isPalindrome(int x) {
        long int num=0;
        int num2=x;
        if(x<0) return false;
        while(x)
        {
            num=num*10+(x%10);
            x/=10;
        }
        return num==num2;
    }
};