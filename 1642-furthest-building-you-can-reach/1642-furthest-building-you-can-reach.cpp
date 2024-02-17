class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i=0;
        for(i;i<heights.size()-1;i++)
        {
            int d=heights[i+1]-heights[i];
            if(d<=0) continue; 
            if(bricks>=d){
                bricks-=d;
                pq.push(d);
            }
            else if(ladders>0)
            {
                if(!pq.empty() && pq.top()>d)
                {
                    bricks+=pq.top()-d;
                    pq.pop();
                    pq.push(d);
                }
                ladders--;
            }
            else break;
        }
        return i;
    }
};