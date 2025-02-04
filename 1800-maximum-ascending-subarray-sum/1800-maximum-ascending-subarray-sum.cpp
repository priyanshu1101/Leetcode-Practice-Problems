class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=0,maxSum=0,prev=-1;
        for(int num:nums){
            if(num>prev){
                sum+=num;
                prev=num;
            }
            else{
                sum=num;
                prev=num;
            }
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};