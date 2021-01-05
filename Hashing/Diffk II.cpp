int Solution::diffPossible(const vector<int> &A, int B) {
    int n = A.size();
    unordered_set<int> s;
    
    for(int i = 0 ; i < n ; i++){
        // Not using abs(A[i]-B) to check as it will also count for the case A[i]+A[j]=B
        if(s.find(A[i]+B) != s.end() || s.find(A[i]-B) != s.end()){
            return 1;
        }
        s.insert(A[i]);
    }
    
    return 0;
}
