class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        vector < vector <int> > dp(t.size()+1, vector <int> (s.size()+1,0));
        
        for(int i = 1; i<dp.size(); i++){
            for(int j = 1; j<dp[0].size(); j++){
                
                if(t[i-1] == s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], max(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        
        if(dp[t.size()][s.size()] == s.size()){
            return 1;
        }
        
        return 0;
    }
};
