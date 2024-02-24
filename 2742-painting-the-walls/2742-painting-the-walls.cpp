class Solution {
public:
    int size;
    int memo[501][501];
    long long solve(vector<int>& cost, vector<int>& time,int i,int wall)
    {
        if(wall<=0) return 0;
        if(i>=size) return INT_MAX;
        if(memo[i][wall]!=-1) return memo[i][wall];
        long long paint=solve(cost,time,i+1,wall-1-time[i])+cost[i];
        long long unPaint=solve(cost,time,i+1,wall);
        return memo[i][wall]=min(paint,unPaint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(memo,-1,sizeof(memo));
        size=time.size();
        return solve(cost,time,0,size);
    }
};