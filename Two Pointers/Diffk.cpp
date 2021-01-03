int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size(), i = 0, j = 1;
    
    while(i <= j && j < n && i < n){
        if(i == j){
            j++;
        }
        
        if(A[j] - A[i] == B){
            return 1;
        }
        else if(A[j] - A[i] < B){
            j++;
        }
        else{
            i++;
        }
    }
    
    return 0;
}
