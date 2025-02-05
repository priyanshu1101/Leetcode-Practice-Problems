class Solution {
public:
    int combination(int n,int r){
        int diff=n-r;
        long long int ans=1;
        for(int i=n;i>max(r,n-r);i--){
            ans*=i;
            ans/=(n-i+1);
        }
        // for(int i=1;i<=min(n-r,r);i++){
        //     ans/=i;
        // }
        return ans;
    }
    int uniquePaths(int m, int n) {
        int totalSteps = m+n-2;
        return combination(totalSteps,m-1);
    }
};