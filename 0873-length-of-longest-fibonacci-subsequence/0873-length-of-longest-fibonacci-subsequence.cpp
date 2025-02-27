class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> st;
        int ans=0;
        for(int num:arr) st.insert(num);
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int num1 = arr[i], num2 = arr[j], sum= arr[i] + arr[j];
                int curr=2;
                while(st.find(sum)!=st.end()){
                    curr++;
                    num1=num2;
                    num2=sum;
                    sum=num1+num2;
                }
                ans=max(ans,curr);
            }
        }
        return ans>=3? ans:0;
    }
};