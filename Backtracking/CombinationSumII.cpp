void combinationSumHelper(vector<int> &A, int start, int sum, vector<int> curr, vector<vector<int>> &res){
    int n = A.size();
    
    // Base Case
    if(sum == 0){
        res.push_back(curr);
        return;
    }
    
    if(start == n || sum < 0) return;
    
    
    // Pre-processing to get the unique element
    int j = start+1;
    while(j < n && A[j] == A[j-1]) j++;
    
    
    // Recursive Step
    
    /* Include the current element 0 times */
    combinationSumHelper(A, j, sum, curr, res);
    
    /* Include the current element 1 or more times */
    for(int i = start ; i < j ; i++){
        curr.push_back(A[i]);
        combinationSumHelper(A, j, sum-(A[i]*(i-start+1)), curr, res);
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    vector<int> curr;
    sort(A.begin(), A.end());
    combinationSumHelper(A, 0, B, curr, res);
    return res;
}
