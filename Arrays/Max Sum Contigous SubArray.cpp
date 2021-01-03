int Solution::maxSubArray(const vector<int> &A) {

    /******************** First Method **************************/
    
    int n = A.size(), max_ele = INT_MIN, curr_sum = 0, max_so_far = INT_MIN;
    
    for(int i = 0 ; i < n ; i++){
       curr_sum += A[i];
       max_ele = max(max_ele, A[i]);
        
       if(curr_sum < 0){
           curr_sum = 0;
       }
       else{
           max_so_far = max(max_so_far, curr_sum);
       }
    }
    
    return max(max_ele, max_so_far);
    
    
    /*************** Alternative - using dp *********************/
    
    int n = A.size(), res = A[0];
    vector<int> dp(n, 0);
    
    dp[0] = A[0];
    
    for(int i = 1 ; i < n ; i++){
        dp[i] = max(A[i], A[i]+dp[i-1]);
        res = max(res, dp[i]);
    }
    
    return res;
}
