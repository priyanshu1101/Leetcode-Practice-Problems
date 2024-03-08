class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq=0,ans=0;
        vector<int> record(101,0);
        for(int i=0;i<nums.size();i++){
            record[nums[i]]++;
            maxFreq=max(maxFreq,record[nums[i]]);
        }
        for(int i=1;i<=100;i++){
            if(record[i]==maxFreq) ans+=maxFreq;
        }
        return ans;

    }
};