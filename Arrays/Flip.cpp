vector<int> Solution::flip(string A) {
    int n = A.size(), cnt = 0, max_cnt = INT_MIN, l, r, ltemp = 0;
    vector<int> res;
    
    // If all are 1s, then return empty vector
    int ones = 0;
    for(int i = 0 ; i < n ; i++){
        if(A[i] == '1'){
            ones++;
        }
    }
    if(ones == n) return res;
    
    // Kadane's Algorithm
    // cnt stores the cnt of 0s minus 1s -> cnt = count(0s) - count(1s)
    // ltemp is the starting of current substring 
    for(int i = 0 ; i < n ; i++){
        A[i]=='1' ? cnt-- : cnt++;
        
        if(cnt > max_cnt){
            max_cnt = cnt;
            l = ltemp;
            r = i;
        }
        
        if(cnt < 0){
            cnt = 0;
            ltemp = i + 1;
        }
    }
    
    res.push_back(l+1);
    res.push_back(r+1);
    
    return res;
}
