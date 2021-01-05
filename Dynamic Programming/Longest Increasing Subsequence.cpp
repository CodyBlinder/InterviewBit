int Solution::lis(const vector<int> &A) {
    int n = A.size(), res = 1;
    vector<int> dp(n, 1);
    
    for(int i = 1 ; i < n ; i++){
        for(int j = i-1 ; j >= 0 ; j--){
            if(A[j] < A[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        res = max(res, dp[i]);
    }
    
    return res;
}
