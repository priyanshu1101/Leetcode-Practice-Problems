class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    bool isValidCell(int i,int j,vector<vector<int>>& grid){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        vector<vector<int>> distance(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> que;
        distance[0][0]=1;
        que.push({1,{0,0}});
        while(!que.empty()){
            pair<int,pair<int,int>> top = que.top();
            que.pop();
            for(auto dir:directions){
                int i = top.second.first + dir[0], j = top.second.second + dir[1] , dist = top.first;
                if(isValidCell(i,j,grid) && distance[i][j]>dist+1){
                    distance[i][j]=dist+1;
                    que.push({dist+1,{i,j}});
                }
            }
        }
        int ans = distance[grid.size()-1][grid[0].size()-1];
        return ans==INT_MAX? -1:ans;
    }
};