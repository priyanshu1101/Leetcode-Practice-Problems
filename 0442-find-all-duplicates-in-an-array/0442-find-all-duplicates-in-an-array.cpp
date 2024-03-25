class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int maxElement=nums.size()+1;
        for(int i=0;i<nums.size();i++){
            int index=(nums[i]%maxElement)-1;
            int multiple=nums[index]/maxElement;
            int remainder=nums[index]%maxElement;
            nums[index]=(multiple+1)*maxElement+remainder;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]/maxElement>1)
                ans.push_back(i+1);
        }
        return ans;
    }
};