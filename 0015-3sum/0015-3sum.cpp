class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(),nums.end());
        int start=0;
        int prev;
        int ptr1=start+1;
        int ptr2=nums.size()-1;
        while(start<=nums.size()-3)
        {
            if(ptr1==ptr2)
            {
                prev=nums[start];
                start++;
                while(start<=nums.size()-3 && nums[start]==prev)
                {
                    prev=nums[start];
                    start++;
                }
                ptr1=start+1;
                ptr2=nums.size()-1;
            }
            else
            {
                if(nums[start]+nums[ptr1]+nums[ptr2]==0)
                {
                    vector<int> subans;
                    subans.push_back(nums[start]);
                    subans.push_back(nums[ptr1]);
                    subans.push_back(nums[ptr2]);
                    ans.push_back(subans);
                    
                    
                    prev=nums[start];
                    start++;
                    while(start<=nums.size()-3 && nums[start]==prev)
                    {
                        prev=nums[start];
                        start++;
                    }
                }
                else if(nums[start]+nums[ptr1]+nums[ptr2]>0)
                {
                    ptr2--;
                }
                else if(nums[start]+nums[ptr1]+nums[ptr2]<0)
                {
                    ptr1++;
                }
            }
        }
        
        
        
        
        // vector<int> subans;
        // subans.push_back(-1);
        // subans.push_back(-1);
        // subans.push_back(2);
        // ans.push_back(subans);
        // subans.clear();
        // subans.push_back(0);
        // subans.push_back(-1);
        // subans.push_back(1);
        // ans.push_back(subans);
        return ans;
    }
};