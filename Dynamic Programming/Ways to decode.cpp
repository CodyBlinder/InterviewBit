int Solution::numDecodings(string A) {
    int n = A.size();
    
    vector<int> dp(n+1, 0);
    dp[n] = 1;
    dp[n-1] = A[n-1]=='0'?0:1;
    
    for(int i = n-2 ; i >= 0 ; i--){
        if(A[i] == '0'){
            dp[i] = 0;
            continue;
        }
        
        dp[i] = dp[i+1];
        
        if(A[i] == '1' || (A[i] == '2' && A[i+1] >= '0' && A[i+1] <= '6')){
            dp[i] += dp[i+2];
        }
    }
    
    return dp[0]%(1000000000+7);
}
