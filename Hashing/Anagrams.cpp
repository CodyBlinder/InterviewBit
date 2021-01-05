vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n = A.size();
    map<map<char, int>, vector<int>> M;
    vector<vector<int>> res;
    
    for(int i = 0 ; i < n ; i++){
        map<char, int> m;
        for(int j = 0 ; j < A[i].size() ; j++){
            m[A[i][j]]++;
        }
        M[m].push_back(i+1);
    }
    
    for(auto it : M){
        res.push_back(it.second);
    }
    
    return res;
}
