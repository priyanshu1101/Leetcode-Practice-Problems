class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> record;
        for(int i=0;i<nums.size();i++){
            record.push_back({nums[i],i});
        }
        sort(record.begin(),record.end());
        int start=0,end=record.size()-1;
        while(start<end){
            int sum=record[start].first+record[end].first;
            if(sum==target) return {record[start].second,record[end].second};
            if(sum<target) start++;
            else end--;
        }
        return {};
    }
};