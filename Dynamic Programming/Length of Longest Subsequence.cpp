int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size(), res = 1;
    vector<int> LIS(n, 1), LDS(n, 1);
    
    if(n == 0) return 0;
    
    for(int i = 1 ; i < n ; i++){
        // Find longest increasing subsequence ending at i
        for(int j = i-1 ; j >= 0 ; j--){
            if(A[j] < A[i]){
                LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
    }
    
    for(int i = n-1 ; i >= 0 ; i--){
        // Find longest decreasing subsequence starting at i
        for(int k = i+1 ; k < n ; k++){
            if(A[i] > A[k]){
                LDS[i] = max(LDS[i], 1 + LDS[k]);
            }
        }
    }
    
    // Reqd longest subsequence will be max(LIS[i]+LDS[i]-1) for 0<=i<n
    for(int i = 0 ; i < n ; i++){
        res = max(res, LIS[i]+LDS[i]-1);
    }
    
    return res;
}
