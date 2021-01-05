int Solution::minimumTotal(vector<vector<int> > &A) {
    int n = A.size();
    
    for(int i = n-1 ; i > 0 ; i--){
        for(int j = 0 ; j < i ; j++){
            A[i-1][j] += min(A[i][j], A[i][j+1]);
        }
    }
    
    return A[0][0];
}
