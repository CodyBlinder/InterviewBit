vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    unordered_map<int, vector<pair<int, int>>> m;
    vector<vector<int>> res;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(m.find(A[i]+A[j]) != m.end()){
                for(auto p : m[A[i]+A[j]]){
                    if(p.first != i && p.second != i && p.first != j && p.second != j){
                        res.push_back({p.first, p.second, i, j});
                    }
                }
            }
            else{
                m[A[i]+A[j]].push_back({i, j});
            }
        }
    }
    
    sort(res.begin(), res.end(), [](vector<int> &v1, vector<int> &v2){
        if(v1[0] == v2[0]){
            if(v1[1] == v2[1]){
                if(v1[2] == v2[2]){
                    return v1[3] < v2[3];
                }
                return v1[2] < v2[2];
            }
            return v1[1] < v2[1];
        }
        return v1[0] < v2[0];
    });
    
    return res[0];
}
