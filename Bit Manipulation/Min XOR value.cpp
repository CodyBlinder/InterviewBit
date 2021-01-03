int Solution::findMinXor(vector<int> &A) {
    
    int n = A.size();
    
    int min_xor = INT_MAX;
    
    std::sort(A.begin(),A.end());
    
    for(int i=0;i<n-1;i++){
        if( (A[i] xor A[i+1]) < min_xor){
            min_xor = A[i] xor A[i+1];
        }
    }
    
    return min_xor;
}
