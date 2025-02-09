class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                int start=j+1,end=nums.size()-1;
                while(start<=end){
                    int mid=(start+end)/2;
                    int value = 0-nums[i]-nums[j];
                    if(value==nums[mid]){
                        ans.push_back({nums[i],nums[j],nums[mid]});
                        start=end+1;
                    }
                    else if(value>nums[mid]){
                        start=mid+1;
                    }
                    else end=mid-1;
                }
                int currValue = nums[j];
                while(j<nums.size() && nums[j]==currValue) j++;
                j--;
            }
            int currValue = nums[i];
            while(i<nums.size() && nums[i]==currValue) i++;
            i--;
        }
        return ans;
    }
};