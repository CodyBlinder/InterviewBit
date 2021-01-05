int Solution::climbStairs(int A) {
    if(A == 0) return 1;
    vector<int> dp(A+1, 0);
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2 ; i <= A ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[A];
}
