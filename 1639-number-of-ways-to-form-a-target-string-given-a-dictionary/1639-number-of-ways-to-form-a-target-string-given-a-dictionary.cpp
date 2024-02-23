class Solution {
public:
    int n; // target size
    int m;  //word size
    const int mod=1e9+7;
    long long solve(string &target,vector<vector<int>> &frequency,int i,int j,vector<string> &words,vector<vector<long long>> &mem)
    {
        if(mem[i][j]!=-1) return mem[i][j];
        if(j==n) return 1;
        if(i==m) return 0;
        long long taken=(solve(target,frequency,i+1,j+1,words,mem)*frequency[target[j]-'a'][i])%mod;
        long long notTaken=solve(target,frequency,i+1,j,words,mem)%mod;
        return mem[i][j]=(taken+notTaken)%mod;
    }
    int numWays(vector<string>& words, string target) {
        n=target.length(); 
        m=words[0].length();
        vector<vector<int>> frequency(27,vector<int>(m,0));
        vector<vector<long long>> mem(1001,vector<long long>(1001,-1));
        for(auto word:words)
        {
            for(int i=0;i<word.length();i++)
            {
                char ch=word[i];
                frequency[ch-'a'][i]++;
            }
        }
        return solve(target,frequency,0,0,words,mem);
    }
};