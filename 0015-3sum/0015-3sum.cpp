class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // T=O(NLogN)
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<nums.size()-2;i++){
            int start=i+1,end=nums.size()-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum==0){
                    st.insert({nums[i],nums[start],nums[end]});
                    start++;
                }
                else if(sum<0) start++;
                else end--;
            }
        }
        for(auto itr=st.begin();itr!=st.end();itr++){
            ans.push_back(*itr);
        }
        return ans;
    }
};