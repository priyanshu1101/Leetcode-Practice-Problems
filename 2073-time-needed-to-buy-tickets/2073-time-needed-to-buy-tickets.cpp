class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        while(tickets[k]!=0){
            for(int i=0;i<tickets.size();i++){
                if(tickets[i]!=0){
                    ans++;
                    tickets[i]--;
                }
            }
        }
        return ans;
    }
};