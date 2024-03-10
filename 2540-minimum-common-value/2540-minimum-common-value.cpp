class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1;
        set<int> st2;
        for(int num:nums1) st1.insert(num);
        for(int num:nums2) st2.insert(num);
        for(auto itr=st1.begin();itr!=st1.end();itr++) if(st2.find(*itr)!=st2.end()) return *itr;
        return -1;
    }
};