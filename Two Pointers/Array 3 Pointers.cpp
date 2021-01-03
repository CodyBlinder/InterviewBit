int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int i = A.size()-1;
    int j = B.size()-1;
    int k = C.size()-1;
    
    int ans = INT_MAX;
    int curr_ans;
    int max_term;
    
    while(i!=-1 && j!=-1 && k!=-1){
        
        curr_ans = max(abs(A[i]-B[j]),max(abs(B[j]-C[k]),abs(C[k]-A[i])));
        
        if(curr_ans <= ans){
            ans = curr_ans;
        }
        
        max_term = max(abs(A[i]-B[j]),max(abs(B[j]-C[k]),abs(C[k]-A[i])));
        
        if(A[i]>=B[j] && A[i]>=C[k]){
            i--;
        }
        else if(B[j]>=A[i] && B[j]>=C[k]){
            j--;
        }
        else{
            k--;
        }
    }
    
    return ans;
}
