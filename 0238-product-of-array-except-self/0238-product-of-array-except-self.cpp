class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        for(int i=0;i<nums.size();i++){
            int leftInd=i;
            int rightInd=nums.size()-1-i;
            if(i==0){
                left[leftInd]=nums[leftInd];
                right[rightInd]=nums[rightInd];
            }
            else{
                left[leftInd]=nums[leftInd]*left[leftInd-1];
                right[rightInd]=nums[rightInd]*right[rightInd+1];
            }
        }
        for(int i=0;i<nums.size();i++){
            int leftVal=(i==0)? 1:left[i-1];
            int rightVal=(i==nums.size()-1)? 1:right[i+1];
            nums[i]=leftVal*rightVal;
        }
        return nums;
    }
};