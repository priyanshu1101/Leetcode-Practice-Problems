class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int>ans(queries);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> que;
        sort(queries.begin(),queries.end());
        int count = 0;
        unordered_map<int,int> record;
        que.push({grid[0][0],{0,0}});
        grid[0][0]*=-1;
        for(int i=0;i<queries.size();i++){
            int query = queries[i];
            while(!que.empty() && que.top().first<query){
                count++;
                pair<int,pair<int,int>> top = que.top();
                que.pop();
                for(auto dir:directions){
                    int i = top.second.first+dir[0],j=top.second.second+dir[1];
                    if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]>0){
                        que.push({grid[i][j],{i,j}});
                        grid[i][j]*=-1;
                    }
                }
            }
            record[query]=count;
        }
        for(int i=0;i<ans.size();i++){
            ans[i]=record[ans[i]];
        }
        return ans;
    }
};