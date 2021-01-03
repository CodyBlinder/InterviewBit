int Solution::removeDuplicates(vector<int> &A) {
    
    int n = A.size(), unq_num = 1;
    if(n == 1) return 1;
    
    for(int i = 1 ; i < n ; i++){
        if(A[i] != A[i-1]){
            unq_num++;
        }
    }
    
    int r = 1, w = 1;
    while(r < n && w < n){
        if(A[r] != A[r-1]){
            A[w] = A[r];
            w++;
        }
        r++;
    }
    
    return unq_num;
}
