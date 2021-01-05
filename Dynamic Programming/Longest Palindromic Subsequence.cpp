int Solution::solve(string A) {
    // // Approach 1 -> Find LCS of A and reverse(A)
    // int n = A.size();
    
    // string B = "";
    // for(int i = n-1 ; i >= 0 ; i--){
    //     B += A[i];
    // }
    
    // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    // // Filling the dp table
    // for(int i = n-1 ; i >= 0 ; i--){
    //     for(int j = n-1 ; j >= 0 ; j--){
    //         if(A[i] == B[j])
    //             dp[i][j] = 1 + dp[i+1][j+1];
    //         else
    //             dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
    //     }
    // }
    
    // return dp[0][0];
    
    // Approach 2 -> Using subarray as the subproblem
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Base Cases
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j)
                dp[i][j] = 1;
        }
    }
    
    // Filling the dp table
    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = i ; j < n ; j++){
            if(A[i] == A[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    
    return dp[0][n-1];
}
