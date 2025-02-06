class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0,end=matrix.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(matrix[mid][0]<=target && matrix[mid][matrix[0].size()-1]>=target)
            {
                int tempStart=0,tempEnd=matrix[0].size()-1;
                while(tempStart<=tempEnd){
                    int tempMid = (tempStart+tempEnd)/2;
                    if(matrix[mid][tempMid]==target) return true;
                    else if(matrix[mid][tempMid]>target) tempEnd=tempMid-1;
                    else tempStart=tempMid+1;
                }
                return false;
            }
            else if(matrix[mid][0]<target){
                start=mid+1;
            }
            else end=mid-1;
        }
        return false;
    }
};