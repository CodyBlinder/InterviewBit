void combineHelper(int n, int start, int k, vector<int> curr, vector<vector<int>> &res){
    // Base Case
    if(k == 0){
        res.push_back(curr);
        return;
    }
    
    if(start > n){
        return;
    }
    
    // Recursive Step
    for(int i = start ; i <= n-k+1 ; i++){
        curr.push_back(i);
        combineHelper(n, i+1, k-1, curr, res);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> res;
    vector<int> curr;
    combineHelper(A, 1, B, curr, res);
    return res;
}
