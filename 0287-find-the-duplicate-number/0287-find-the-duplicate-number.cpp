class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[0];
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                int temp=nums[0];
                while(temp!=slow){
                    temp=nums[temp];
                    slow=nums[slow];
                }
                return temp;
            };
        }
        return -1;
    }
};