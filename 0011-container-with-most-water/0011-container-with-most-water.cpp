class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        vector<int> ltr(height);
        vector<int> rtl(height);
        for(int i=1;i<height.size();i++){
            ltr[i]=max(ltr[i],ltr[i-1]);
        }
        for(int i=height.size()-2;i>=0;i--){
            rtl[i]=max(rtl[i+1],rtl[i]);
        }
        int left=0,right=height.size()-1;
        while(left<right){
            int currentWaterCapacity=(right-left)*min(ltr[left],rtl[right]);
            ans=max(ans,currentWaterCapacity);
            if(ltr[left]<=rtl[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};