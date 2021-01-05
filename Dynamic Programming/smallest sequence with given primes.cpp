vector<int> Solution::solve(int A, int B, int C, int D) {
    int x = 0, y = 0, z = 0;
    
    vector<int> dp(D+1, 0);
    dp[0] = 1;
    
    for(int i = 1 ; i <= D ; i++){
        dp[i] = min(A*dp[x], min(B*dp[y], C*dp[z]));
        
        if(dp[i] == A*dp[x]){
            x++;
        }
        
        if(dp[i] == B*dp[y]){
            y++;
        }
        
        if(dp[i] == C*dp[z]){
            z++;
        }
    }
    
    dp.erase(dp.begin());
    return dp;
}
