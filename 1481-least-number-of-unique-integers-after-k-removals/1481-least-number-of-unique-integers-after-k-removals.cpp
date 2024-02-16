class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto i:arr) mp[i]++;
        vector<int> record;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
            record.push_back(itr->second);
        sort(record.begin(),record.end());
        int ans=record.size();
        for(int i=0;i<record.size();i++)
        {
            if(k<=0) break;
            if(record[i]-k<=0)
            {            
                k=k-record[i];
                ans--;
            }
        }
        return ans;
    }
};