int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    
    // Base Cases
    dp[m-1][n-1] = A[m-1][n-1]>=0 ? 1 : 1-A[m-1][n-1];
    
    // Filling the dp table
    for(int i = m-1 ; i >= 0 ; i--){
        for(int j = n-1 ; j >= 0 ; j--){
            if(i == m-1 && j == n-1) continue;
            if(i+1 < m)
                dp[i][j] = min(dp[i][j], max(1, dp[i+1][j]-A[i][j]));
            if(j+1 < n)
                dp[i][j] = min(dp[i][j], max(1, dp[i][j+1]-A[i][j]));
        }
    }
    
    return dp[0][0];
}
