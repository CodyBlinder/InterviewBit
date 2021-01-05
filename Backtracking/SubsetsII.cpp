void subsetsWithDupHelper(vector<int> &A, int start, vector<int> curr, vector<vector<int>> &res){
    int n = A.size();
    
    // Base Case
    if(start == n){
        res.push_back(curr);
        return;
    }
    
    
    // Pre-processing to find starting of unique element
    int j = start+1;
    while(j < n && A[j] == A[j-1]) j++;
    
    
    // Recursive Step
    
    /* Include current element 0 times */
    subsetsWithDupHelper(A, j, curr, res);
    
    /* Include current element 1 or more times */
    for(int i = start ; i < j ; i++){
        curr.push_back(A[i]);
        subsetsWithDupHelper(A, j, curr, res);
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> curr;
    sort(A.begin(), A.end());
    subsetsWithDupHelper(A, 0, curr, res);
    sort(res.begin(), res.end());
    return res;
}
