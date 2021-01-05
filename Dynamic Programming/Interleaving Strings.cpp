int Solution::isInterleave(string A, string B, string C) {
    // // This is wrong solution 
    // // Take A='YX', B='X' and C='XXY'
    // // This solution will give true, but it should be false
    // // Test Cases need to be improved
    // A = A.append(B);
    // sort(A.begin(), A.end());
    // sort(C.begin(), C.end());
    // return A==C ? 1 : 0;
    
    int m = A.size(), n = B.size();
    if(m+n != C.size()) return false;
    
    // dp(i, j) => Whether C[0....i+j-1] is an interleaving of  A[0....i-1] and B[0....j-1]
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    
    // Base Cases
    dp[0][0] = true;
    
    for(int i = 1 ; i <= n ; i++){
        if(B[i-1] == C[i-1])
            dp[0][i] = dp[0][i-1];
    }
    
    for(int j = 1 ; j <= m ; j++){
        if(A[j-1] == C[j-1])
            dp[j][0] = dp[j-1][0];
    }
    
    
    // Filling the dp table
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            
            // curr element of C is equal to that of A, but not B
            if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1])
                dp[i][j] = dp[i-1][j];
            
            // curr element of C is equal to that of B, but not A
            else if(A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1])
                dp[i][j] = dp[i][j-1];
            
            // curr element of C is equal to that of both A and B
            else if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1])
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                
        }
    }
    
    return dp[m][n];
}
