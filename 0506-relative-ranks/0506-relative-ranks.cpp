class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        for(int i=0;i<score.size();i++) ans.push_back(to_string(score[i]));
        sort(score.begin(),score.end(),greater<int>());
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<score.size();j++){
                if(score[j]==stoi(ans[i])){
                    if(j==0) ans[i]="Gold Medal";
                    else if(j==1) ans[i]="Silver Medal";
                    else if(j==2) ans[i]="Bronze Medal";
                    else ans[i]=to_string(j+1);
                    break;
                }
            }
        }
        return ans;
    }
};