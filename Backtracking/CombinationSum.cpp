void combinationSumHelper(vector<int> &A, int start, int sum, vector<int> curr, vector<vector<int>> &res){
    int n = A.size();
    
    // Base Case
    if(sum == 0){
        res.push_back(curr);
        return;
    }
    
    if(start == n || sum < 0){
        return;
    }
    
    // Recursive Step
    for(int i = start ; i < n ; i++){
        curr.push_back(A[i]);
        combinationSumHelper(A, i, sum-A[i], curr, res);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    vector<int> curr;
    
    set<int> s;
    for(int i = 0 ; i < A.size() ; i++){
        s.insert(A[i]);
    }
    
    vector<int> nums;
    for(auto it : s){
        nums.push_back(it);
    }
    
    // set has already taken care of keeping nums in sorted order
    // If we use unordered_set, then we would need to sort nums
    combinationSumHelper(nums, 0, B, curr, res);
    return res;
}
