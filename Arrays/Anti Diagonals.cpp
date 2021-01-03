vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> res;
    vector<int> v;
    
    for(int k = 0 ; k <= (n-1)*2 ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i+j == k){
                    v.push_back(A[i][j]);
                }
            }
        }
        if(v.size() == 0) continue;
        res.push_back(v);
        v.clear();
    }
    
    return res;
}
