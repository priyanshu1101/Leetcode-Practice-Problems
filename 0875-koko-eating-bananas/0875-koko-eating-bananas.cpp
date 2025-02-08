class Solution {
public:
    int timeTakenToEatAll(vector<int>& piles,int maxEdiblePerHour){
        int totalTimeTaken=0;
        for(int i=0;i<piles.size();i++){
            totalTimeTaken+=piles[i]/maxEdiblePerHour + (piles[i]%maxEdiblePerHour? 1:0);
        }
        return totalTimeTaken;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maximumNumber = INT_MIN;
        for(int pile:piles) maximumNumber = max(maximumNumber,pile);
        int start=1,end=maximumNumber;
        int mid;
        int ans=INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            if(timeTakenToEatAll(piles,mid)<=h){
                end=mid-1;
                ans=min(mid,ans);
            }
            else start=mid+1;
        }
        return ans==INT_MAX? -1:ans;
    }
};