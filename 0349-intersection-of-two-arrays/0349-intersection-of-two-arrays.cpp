class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st1;
        unordered_set<int> st2;
        for(int i=0;i<max(nums1.size(),nums2.size());i++){
            if(nums1.size()>i)
                st1.insert(nums1[i]);
            if(nums2.size()>i)
                st2.insert(nums2[i]);
        }
        for(auto itr=st1.begin();itr!=st1.end();itr++){
            if(st2.find(*itr)!=st2.end())
                ans.push_back(*itr);
        }
        return ans;
        
    }
};