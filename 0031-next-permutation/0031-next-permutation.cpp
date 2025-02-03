class Solution {
public:
    int findBreakPoint(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1])
                return i - 1;
        }
        return -1;
    }
    int findLastIndexGreaterThanBreakPoint(vector<int>& nums, int breakPoint) {
        for (int i = nums.size() - 1; i >= breakPoint; i--) {
            if (nums[i] > nums[breakPoint])
                return i;
        }
        return breakPoint;
    }
    void nextPermutation(vector<int>& nums) {
        int breakPoint = findBreakPoint(nums);
        if (breakPoint != -1) {
            int lastIndexGreaterThanBreakPoint =
                findLastIndexGreaterThanBreakPoint(nums, breakPoint);
            swap(nums[breakPoint], nums[lastIndexGreaterThanBreakPoint]);
        }
        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};