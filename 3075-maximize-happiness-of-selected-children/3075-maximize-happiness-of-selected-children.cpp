class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        long long ans=0;
        for(int i=0;i<happiness.size();i++){
            pq.push(happiness[i]);
        }
        for(int i=0;i<k;i++){
            int value=pq.top()-i;
            ans+=value>0? value:0;
            pq.pop();
        }
        return ans;
    }
};