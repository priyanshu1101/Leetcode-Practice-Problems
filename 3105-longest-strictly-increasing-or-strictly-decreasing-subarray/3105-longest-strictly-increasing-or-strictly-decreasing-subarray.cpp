class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si = 1, sd = 1, maxAns = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                si++;
                sd = 1;
            } else if (nums[i] > nums[i + 1]) {
                si--;
                sd++;
            } else {
                si = 1;
                sd = 1;
            }
            maxAns = max(maxAns, max(si, sd));
        }
        return maxAns;
    }
};