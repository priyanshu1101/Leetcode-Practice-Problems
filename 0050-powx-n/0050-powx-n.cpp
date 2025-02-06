class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool neg=n<0;
        long long int nn=abs(n);
        cout<<nn;
        while(nn)
        {
            if(nn%2==0)
            {
                x*=x;
                nn=nn/2;
            }
            else
            {
                ans*=x;
                nn--;
            }
        }
        return neg? 1/ans:ans;
    }
};