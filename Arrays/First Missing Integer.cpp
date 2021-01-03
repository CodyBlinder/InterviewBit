int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    
    // Transform the array into arr[i] = i+1
    for(int i = 0 ; i < n ; i++){
        if(A[i] <= 0 || A[i] > n){
            continue;
        }
        
        while(A[A[i]-1] != A[i]){
            swap(A[A[i]-1], A[i]);
            if(A[i] <= 0 || A[i] > n){
                break;
            }
        }
    }
    
    // First position at which -1 is encountered gives the first missing positive number
    for(int i = 0 ; i < n ; i++){
        if(A[i] != i+1){
            return i+1;
        }
    }
    
    return n+1;
}
