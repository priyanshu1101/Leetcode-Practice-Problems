class Solution {
public:
    void initialiseRef(vector<int>& leftMost,vector<int>& rightMost){
        int lmost=0;
        int rmost=0;
        for(int i=0;i<leftMost.size();i++){
            leftMost[i]=max(lmost,leftMost[i]);
            lmost=leftMost[i];
            rightMost[rightMost.size()-i-1]=max(rmost,rightMost[rightMost.size()-i-1]);
            rmost=rightMost[rightMost.size()-i-1];
        }
    }
    int trap(vector<int>& height) {
        vector<int> leftMost= height;
        vector<int> rightMost = height;
        initialiseRef(leftMost,rightMost);
        int waterCapacity=0;
        for(int i=0;i<height.size();i++){
            waterCapacity+=min(leftMost[i],rightMost[i])-height[i];
        }
        return waterCapacity;
    }
};