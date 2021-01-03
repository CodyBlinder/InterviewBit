void Solution::merge(vector<int> &A, vector<int> &B) {
    
    int n = A.size(), m = B.size();
    
    int i = n, j = m, k = m+n-1;
    
    while(i >= 0 && j >= 0){
        if(A[i] > B[j]){
            A[k] = A[i];
            i--;
        }
        else{
            A[k] = B[j];
            j--;
        }
        k--;
    }
    
    while(j >= 0){
        A[k] = B[j];
        j--;
        k--;
    }
}
