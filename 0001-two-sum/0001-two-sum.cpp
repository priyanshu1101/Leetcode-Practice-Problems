class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> record; // S=O(N)
        for(int i=0;i<nums.size();i++){ // T=O(N)
            record.push_back({nums[i],i});
        }
        sort(record.begin(),record.end()); // T=O(NlogN)
        int start=0,end=record.size()-1;
        while(start<end){ // T=O(N)
            int sum=record[start].first+record[end].first;
            if(sum==target) return {record[start].second,record[end].second};
            if(sum<target) start++;
            else end--;
        }
        return {};
    }
};