class Solution {
public:
    bool isEmpty(vector<int> nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=INT_MIN) return false;
        }
        return true;
    }
    void ansFinder(vector<int> nums,vector<vector<int>>& ans,vector<int> subans){
        if(isEmpty(nums)){
            ans.push_back(subans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==INT_MIN) continue;
            int value = nums[i];
            subans.push_back(value);
            nums[i]=INT_MIN;
            ansFinder(nums,ans,subans);
            nums[i]=value;
            subans.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subans;
        ansFinder(nums,ans,subans);
        return ans;
    }
};