void permuteHelper(vector<int> &A, vector<bool> &visited, vector<int> curr, vector<vector<int>> &res){
    int n = A.size();
    
    // Base Case
    if(curr.size() == n){
        res.push_back(curr);
        return;
    }
    
    // Recursive Step
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            visited[i] = true;
            curr.push_back(A[i]);
            permuteHelper(A, visited, curr, res);
            curr.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> curr;
    vector<bool> visited(A.size(), false);
    permuteHelper(A, visited, curr, res);
    return res;
}
