class Solution {
public:
    int permutation(int n,int r){
        int ans=1;
        for(int i=n;i>n-r;i--)
        {
            ans*=i;
        }
        return ans;
    }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long int value = nums[i]*nums[j];
                mp[value]++;
            }
        }
        for(auto itr = mp.begin();itr!=mp.end();itr++){
            if(itr->second>1){
                ans+=permutation(itr->second,2)*4;
            }
        }
        return ans;
    }
};