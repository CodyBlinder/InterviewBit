int Solution::numDistinct(string A, string B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    // Base Cases
    for(int i = 0 ; i <= m ; i++){
        dp[i][n] = 1;
    }
    
    // Filling the dp table
    for(int i = m-1 ; i >= 0 ; i--){
        for(int j = n-1 ; j >= 0 ; j--){
            if(A[i] == B[j])
                dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
            else
                dp[i][j] = dp[i+1][j];
        }
    }
    
    return dp[0][0];
}
