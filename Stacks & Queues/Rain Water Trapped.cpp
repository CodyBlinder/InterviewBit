int Solution::trap(const vector<int> &A) {
    
    int n = A.size();
    
    int prev = A[0];
    int prev_idx = 0;
    int water = 0;
    int temp = 0;
    
    for(int i=0;i<n;i++){
        if(A[i]>=prev){
            prev = A[i];
            prev_idx = i;
            temp=0;
        }
        else{
            water += prev-A[i];
            temp += prev-A[i];
        }
    }
    
    if(prev_idx < n-1){
        water -= temp;
        prev = A[n-1];
        
        for(int i=n-1;i>=prev_idx;i--){
            if(A[i] >= prev){
                prev = A[i];
            }
            else{
                water += prev-A[i];
            }
        }
    }
    
    return water;
}
