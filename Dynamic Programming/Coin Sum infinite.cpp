int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size(), m = 1000007;
    vector<int> dp(B+1, 0);
    
    // Base Cases
    for(int j = 0 ; j <= B ; j++){
        if(j%A[n-1] == 0)
            dp[j] = 1;
    }
    
    // Filling the dp table
    for(int i =n-2 ; i >= 0 ; i--){
        for(int j = 0 ; j <= B ; j++){
            if(j >= A[i])
                dp[j] = (dp[j-A[i]] + dp[j])%m;
        }
    }
    
    return dp[B];
}
