class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballPos,colorFr;
        vector<int>ans;
        int distinct=0;
        for(vector<int> query: queries){
            if(ballPos[query[0]]!=0){
                if(--colorFr[ballPos[query[0]]]==0) distinct--;
                ballPos[query[0]]=query[1];
                colorFr[query[1]]++;
                if(colorFr[query[1]]==1) distinct++;
            }else{
                ballPos[query[0]]=query[1];
                colorFr[query[1]]++;
                if(colorFr[query[1]]==1) distinct++;
            }
            ans.push_back(distinct);
        }
        return ans;
    }
};