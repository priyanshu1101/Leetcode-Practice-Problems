class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int maxScore=0;
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power)
            {
                power-=tokens[i++];
                score++;
            }
            else if(tokens[i]>=power && score!=0){
                power+=tokens[j--];
                score--;
            }
            else break;
            maxScore=max(score,maxScore);
        }
        return maxScore;
    }
};