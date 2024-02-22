class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return n;
        unordered_map<int,int> map;
        for(int i=0;i<trust.size();i++)
        {
            if(map[trust[i][0]]!=-1) map[trust[i][0]]=-1;
            if(map[trust[i][1]]!=-1) map[trust[i][1]]++;
        }
        for(auto itr=map.begin();itr!=map.end();itr++)
        {
            if(itr->second==n-1) return itr->first;
        }
        return -1;
    }
};