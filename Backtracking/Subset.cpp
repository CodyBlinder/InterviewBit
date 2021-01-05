void subsetsHelper(vector<int> &A, int start, vector<int> curr, vector<vector<int>> &res){
    int n = A.size();
    
    // Base Case
    if(start == n){
        res.push_back(curr);
        return;
    }
    
    // Recursive Step
    subsetsHelper(A, n, curr, res);
    
    for(int i = start ; i < n ; i++){
        curr.push_back(A[i]);
        subsetsHelper(A, i+1, curr, res);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> curr;
    sort(A.begin(), A.end());
    subsetsHelper(A, 0, curr, res);
    sort(res.begin(), res.end());
    return res;
}
