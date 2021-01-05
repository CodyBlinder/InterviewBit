int Solution::solve(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size(), res = A[m-1][n-1], a, b;
    vector<vector<int>> rsum = A, dp(m, vector<int>(n, 0));
    
    // Pre-processing the rsum matrix
    for(int i = 0 ; i < m ; i++){
        for(int j = n-2 ; j >= 0 ; j--){
            rsum[i][j] = A[i][j] + rsum[i][j+1];
        }
    }
    
    // Filling the dp table
    for(int j = n-1 ; j >= 0 ; j--){
        for(int i = m-1 ; i >= 0 ; i--){
            a = 0, b = 0;
            
            if(i != m-1)
                a = dp[i+1][j];
            if(j != n-1)
                b = rsum[i][j+1];
                
            dp[i][j] = A[i][j] + a + b;
            res = max(res, dp[i][j]);
        }
    }
    
    return res;
}
