class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        m--;
        n--;
        while (m!=-1 && n!=-1) {
            if (nums1[m] > nums2[n]) {
                swap(nums1[m--], nums1[last--]);
            } else
                swap(nums1[last--], nums2[n--]);
        }
        while (n!=-1) {
            swap(nums1[last--], nums2[n--]);
        }
    }
};