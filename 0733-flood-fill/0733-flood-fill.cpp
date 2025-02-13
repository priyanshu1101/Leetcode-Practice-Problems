class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> que;
        int initialValue = image[sr][sc];
        if(initialValue==color) return image;
        que.push({sr,sc});
        while(!que.empty()){
            pair<int,int> topPair=que.front();
            int i=topPair.first;
            int j=topPair.second;
            image[i][j]=color;
            que.pop();
            if(i-1>=0 && image[i-1][j]==initialValue){que.push({i-1,j});} // top
            if(i+1<image.size() && image[i+1][j]==initialValue){que.push({i+1,j});} // bottom
            if(j-1>=0 && image[i][j-1]==initialValue){que.push({i,j-1});} //left
            if(j+1<image[0].size() && image[i][j+1]==initialValue){que.push({i,j+1});} //right
        }
        return image;
    }
};