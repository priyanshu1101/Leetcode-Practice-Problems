class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=-1,two=nums.size();
        int i=0;
        while(zero<two && i<two){
            if(nums[i]==0){
                swap(nums[i++],nums[++zero]);
            }
            else if(nums[i]==2){
                swap(nums[i],nums[--two]);
            }
            else i++;
        }
    }
};