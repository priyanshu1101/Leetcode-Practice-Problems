class Solution {
public:
    bool check(vector<int>& nums) {
        int currSorted=1;
        int maxAns=INT_MIN;
        for(int i=0;i<2*nums.size()-1;i++){
            int index = i%nums.size();
            if(nums[index]<=nums[(i+1)%nums.size()]) currSorted++;
            else currSorted=1;
            maxAns=max(maxAns,currSorted);
        }
        return maxAns>=nums.size();
    }
};