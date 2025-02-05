class Solution {
public:
    int count =0;
    bool checkTriplet(int val1,int val2,int val3,int a,int b,int c){
        if(abs(val1-val2)<=a && abs(val2-val3)<=b && abs(val1-val3)<=c)
            return true;
        return false;
    }
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                for(int k=j+1;k<arr.size();k++){
                    if(checkTriplet(arr[i],arr[j],arr[k],a,b,c)) count++;
                }
            }
        }
        return count;
    }
};