class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int currValue = i - nums[i];
            int size = nums.size() - i - 1;
            ans += size - mp[currValue];
            mp[currValue]++;
        }
        return ans;
    }
};