class Solution {
public:
    int pivotInteger(int n) {
        int start=1,end=n;
        while(start<=end){
            int i=(start+end)/2;
            int first=(i/2.0)*((2*1)+(i-1));
            int second=((n-i+1)/2.0)*((2*i)+((n-i+1)-1));
            if(first==second) return i;
            if(first<second) start=i+1;
            if(first>second) end=i-1;
        }
        return -1;
    }
};