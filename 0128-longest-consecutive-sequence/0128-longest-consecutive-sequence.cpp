class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        int count=0;
        int maxcount=0;
        for(int i=0;i<nums.size();i++)
        {
            
            if(st.find(nums[i]-1)==st.end())
            {
                count=0;
                for(int j=nums[i];j<=INT_MAX;j++)
                {
                    if(st.find(j)!=st.end())
                    {
                            count++;
                            maxcount=max(maxcount,count);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return maxcount;
    }
};