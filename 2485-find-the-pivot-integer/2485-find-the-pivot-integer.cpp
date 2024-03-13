class Solution {
public:
    int pivotInteger(int n) {
        int first=0;
        int second=0;
        for(int i=1;i<=n;i++){
            first=(i/2.0)*((2*1)+(i-1));
            second=((n-i+1)/2.0)*((2*i)+((n-i+1)-1));
            cout<<first<<" "<<second<<endl;
            if(first==second) return i;
        }
        return -1;
    }
};