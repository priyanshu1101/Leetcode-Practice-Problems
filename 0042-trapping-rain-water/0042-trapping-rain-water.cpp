class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> ltr(height); // left to right
        vector<int> rtl(height); // right to left

        for(int i=1;i<height.size();i++){ 
            ltr[i]=max(ltr[i],ltr[i-1]);
        }
        
        for(int i=height.size()-2;i>=0;i--){
            rtl[i]=max(rtl[i],rtl[i+1]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=min(ltr[i],rtl[i])-height[i];
        }
        return ans;
    }
};