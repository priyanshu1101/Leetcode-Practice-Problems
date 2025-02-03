class Solution {
public:
    vector<vector<int>> ans;
    void ansFinder(vector<int>nums,int i){
        if(i==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            ansFinder(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       ansFinder(nums,0);
       return ans; 
    }
};