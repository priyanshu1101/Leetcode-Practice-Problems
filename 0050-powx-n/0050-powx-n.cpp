class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool neg=n<0;
        n=abs(n);
        while(n)
        {
            if(n%2==0)
            {
                x*=x;
                n=n/2;
            }
            else
            {
                ans*=x;
                n--;
            }
        }
        return neg? 1/ans:ans;
    }
};