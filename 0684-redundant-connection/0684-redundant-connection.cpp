#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        vector<int> rank(n + 1, 1);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int rootU = find(u, parent);
            int rootV = find(v, parent);
            
            if (rootU == rootV) {
                return {u, v};
            } else {
                if (rank[rootU] > rank[rootV]) {
                    parent[rootV] = rootU;
                } else if (rank[rootV] > rank[rootU]) {
                    parent[rootU] = rootV;
                } else {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        }
        
        return {};
    }
    
private:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
};