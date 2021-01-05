int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(C+1, 0));
    
    // Base Cases
    for(int j = 0 ; j <= C ; j++){
        dp[n-1][j] = (B[n-1]<=j ? A[n-1] : 0);
    }
    
    // Filling the dp table
    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = 0 ; j <= C ; j++){
            if(B[i] <= j){
                dp[i][j] = max(A[i]+dp[i+1][j-B[i]], dp[i+1][j]);
            }
            else{
                dp[i][j] = dp[i+1][j];
            }
        }
    }
    
    return dp[0][C];
}
