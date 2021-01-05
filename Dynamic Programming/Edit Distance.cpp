int Solution::minDistance(string A, string B) {
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 1));
    
    // Base Cases
    for(int i = 0 ; i <= n ; i++){
        dp[m][i] = n-i;
    }
    
    for(int j = 0 ; j <= m ; j++){
        dp[j][n] = m-j;
    }
    
    
    // Filling the dp table
    for(int i = m-1 ; i >= 0 ; i--){
        for(int j = n-1 ; j >= 0 ; j--){
            if(A[i] == B[j])
                dp[i][j] = dp[i+1][j+1];
            else
                dp[i][j] = min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
        }
    }
    
    return dp[0][0];
}
