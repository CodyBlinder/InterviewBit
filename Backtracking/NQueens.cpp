void solveNQueensHelper(int k, vector<bool> &col, vector<bool> &d1, vector<bool> &d2, vector<string> curr, vector<vector<string>> &res){
    int n = col.size(); // No. of columns
    
    // Base Cases
    if(k == n){
        res.push_back(curr);
        return;
    }
    
    // Recursive Step
    for(int i = 0 ; i < n ; i++){
        if(!col[i] && !d1[k-i+n-1] && !d2[k+i]){
            col[i] = true;
            d1[k-i+n-1] = true;
            d2[k+i] = true;
            curr[k][i] = 'Q';
            solveNQueensHelper(k+1, col, d1, d2, curr, res);
            curr[k][i] = '.';
            d2[k+i] = false;
            d1[k-i+n-1] = false;
            col[i] = false;
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> res;
    vector<string> curr(A, string(A, '.'));
    vector<bool> col(A, false);
    vector<bool> d1(2*A-1, false);
    vector<bool> d2(2*A-1, false);
    solveNQueensHelper(0, col, d1, d2, curr, res);
    return res;
}
