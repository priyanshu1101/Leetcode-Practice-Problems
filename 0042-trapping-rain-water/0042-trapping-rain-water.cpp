class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=height[0];
        int rightMax=height[n-1];
        int i=0,j=n-1;
        int water=0;
        while(i<=j)
        {
            if(leftMax<=rightMax)
            {
                leftMax=max(leftMax,height[i]);
                water+=leftMax-height[i];
                i++;
            }
            else
            {
                rightMax=max(rightMax,height[j]);
                water+=rightMax-height[j];
                j--;
            }
        }
        return water;
    }
};