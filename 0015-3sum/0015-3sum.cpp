class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int ptr1=i+1;
            int ptr2=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            while(ptr1<ptr2)
            {
                if(nums[ptr1]+nums[ptr2]+nums[i]==0)
                {
                    vector<int> subans{nums[ptr1],nums[ptr2],nums[i]};
                    ans.push_back(subans);
                    ptr1++;
                    for(int j=ptr1;ptr1<ptr2 && j<ptr2;j++)
                    {
                        if(nums[ptr1]==nums[ptr1-1])
                            ptr1++;
                        else
                            break;
                    }
                    ptr2--;
                    for(int j=ptr2;ptr1<ptr2 && j>ptr1;j--)
                    {
                        if(nums[ptr2]==nums[ptr2+1])
                            ptr2--;
                        else
                            break;
                    }
                }
                else if(nums[ptr1]+nums[ptr2]+nums[i]<0)
                {
                    ptr1++;
                }
                else if(nums[ptr1]+nums[ptr2]+nums[i]>0)
                {
                    ptr2--;
                }
            }
        }
        return ans;
    }
};