int Solution::anytwo(string A) {
    // Approach -> Find the length of longest repeating subsequence (l)
    // If l >= 2 then condition is satisfied, else not
    
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    // Base Cases
    // Already set as initialized to 0
    
    
    // Filling the dp table
    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = n-1 ; j >= i ; j--){
            if(i != j && A[i] == A[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    
    return dp[0][0]>=2 ? 1 : 0;
}
