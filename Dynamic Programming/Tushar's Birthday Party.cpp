int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n = B.size();
    long long res = 0, maxi = 0;
    maxi = *max_element(A.begin(), A.end());
    
    vector<long long> dp(maxi+1, INT_MAX);
    
    // Base Cases 
    for(int j = 0 ; j <= maxi ; j++){
        if(j%B[n-1] == 0)
            dp[j] = (j/B[n-1])*(C[n-1]);
    }
    
    // Filling the dp table
    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = 0 ; j <= maxi ; j++){
            if(j-B[i] >= 0)
                dp[j] = min(dp[j], C[i]+dp[j-B[i]]);
        }
    }
    
    // Summing for all capacities
    for(int i = 0 ; i < A.size() ; i++){
        res += dp[A[i]];
    }
    
    return res;
}
