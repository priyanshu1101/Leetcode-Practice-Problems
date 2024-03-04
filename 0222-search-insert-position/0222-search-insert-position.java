public class Solution {
    public int searchInsert(int[] A, int target) {
        int len = A.length;
        for(int i = 0; i < len; i++) {
            if (A[i] >= target)
                return i;
            if (A[i] < target)
                continue;
        }
        return len;
    }
}