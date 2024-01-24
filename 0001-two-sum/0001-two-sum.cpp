class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int val=target-nums[i];
            if(mp.find(target-nums[i])!=mp.end() && mp[val]!=i)
                return {i,mp[val]};
            mp[nums[i]]=i;
        }
        // for(int i=0;i<nums.size();i++)
        // {
        //     int val=target-nums[i];
        //     if(mp.find(target-nums[i])!=mp.end() && mp[val]!=i)
        //         return {i,mp[val]};
        // }
        return {};
    }
};