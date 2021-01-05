bool isPalin(string &A){
    int n = A.size(), start = 0, end = n-1;
    while(start <= end){
        if(A[start] != A[end])
            return false;
        start++; end--;
    }
    return true;
}

void partitionHelper(string A, int start, vector<string> curr, vector<vector<string>> &res){
    int n = A.size();
    
    // Base Case
    if(start == n){
        res.push_back(curr);
        return;
    }
    
    // Recursive Step
    string subStr = "";
    for(int i = start ; i < n ; i++){
        subStr += A[i];
        if(isPalin(subStr)){
            curr.push_back(subStr);
            partitionHelper(A, i+1, curr, res);
            curr.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> res;
    vector<string> curr;
    partitionHelper(A, 0, curr, res);
    return res;
}
