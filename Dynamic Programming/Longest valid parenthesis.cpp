int Solution::longestValidParentheses(string A) {
    int n = A.size(), MatchIdx, max_len = INT_MIN;
    vector<int> dp(n, 0);
    
    dp[0] = 0;
    max_len = 0;
    
    for(int i = 1 ; i < n ; i++){
        if(A[i] == ')'){
            MatchIdx = i-dp[i-1]-1;
            if(MatchIdx >= 0 && A[MatchIdx] == '('){
                dp[i] = 2 + dp[i-1];
                if(MatchIdx-1 >= 0){
                    dp[i] += dp[MatchIdx-1];
                }
            }
        }
        
        max_len = max(max_len, dp[i]);
    }
    
    return max_len;
}
