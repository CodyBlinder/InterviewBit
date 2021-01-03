vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> res;
    vector<int> v;
    
    if(A == 0) return res;
    
    res.push_back({1});
    
    for(int k = 1 ; k < A ; k++){
        v.push_back(1);
        for(int i = 1 ; i < k ; i++){
            v.push_back(res[res.size()-1][i-1] + res[res.size()-1][i]);
        }
        v.push_back(1);
        res.push_back(v);
        v.clear();
    }
    
    return res;
}
