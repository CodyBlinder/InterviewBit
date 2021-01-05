int Solution::minPathSum(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
    
    // Filling the dp table
    for(int i = m-1 ; i >= 0 ; i--){
        for(int j = n-1 ; j >= 0 ; j--){
            if(i == m-1 && j == n-1)
                dp[i][j] = A[i][j];
            else
                dp[i][j] = A[i][j] + min(dp[i+1][j], dp[i][j+1]);
        }
    }
    
    return dp[0][0];
}
