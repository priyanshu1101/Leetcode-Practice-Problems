class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int initialRange = 0;
        int newRange=0;
        int jump=0;
        for(int i=0;i<nums.size();i++){
            newRange = max(newRange,i+nums[i]);
            if(i==initialRange){
                jump++;
                initialRange = newRange;
                newRange=0;
                if(initialRange>=nums.size()-1) return jump;
            }
        }
        return -1;
    }
};