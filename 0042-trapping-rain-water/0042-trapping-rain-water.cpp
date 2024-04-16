class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,leftMax=0,rightMax=0,ans=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]<leftMax) ans+=leftMax-height[l];
                else leftMax=height[l];
                l++;
            }
            else{
                if(height[r]<rightMax) ans+=rightMax-height[r];
                else rightMax=height[r];
                r--;
            }
        }
        return ans;
    }
};