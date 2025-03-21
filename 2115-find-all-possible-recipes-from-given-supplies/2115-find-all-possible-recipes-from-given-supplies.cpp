class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> indegree;
        unordered_map<string,vector<string>> adj;
        unordered_set<string> recipesRecord;
        vector<string> ans;
        stack<string> stk;
        for(int i=0;i<ingredients.size();i++){
            string recipi=recipes[i];
            recipesRecord.insert(recipi);
            for(string ingredient:ingredients[i]){
                adj[ingredient].push_back(recipi);
                indegree[recipi]++;
            }
        }
        for(int i=0;i<supplies.size();i++){
            stk.push(supplies[i]);
        }
        while(!stk.empty()){
            string top=stk.top();
            if(recipesRecord.find(top)!=recipesRecord.end()) ans.push_back(top);
            stk.pop();
            for(string adjNode:adj[top]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0){
                    stk.push(adjNode);
                }
            }
        }
        return ans;
    }
};