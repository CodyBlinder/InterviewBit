vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, vector<pair<int, int>>> m;
    vector<int> v;
    set<vector<int>> s;
    vector<vector<int>> res;
    
    // Hash map to store sums of all possible pairs
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            m[A[i]+A[j]].push_back(make_pair(i, j));
        }
    }
    
    // Traverse through each pair and search for target-sum(pair) in Hash map
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            int sum = A[i]+A[j];
            if(m.find(B-sum) != m.end()){
                vector<pair<int, int>> vp = m[B-sum];
                for(auto temp : vp){
                    auto p = temp;
                    if(p.first != i && p.second != i && p.first != j && p.second != j){
                        v = {A[p.first], A[p.second], A[i], A[j]};
                        sort(v.begin(), v.end());
                        s.insert(v);
                    }
                }
            }
        }
    }
    
    for(auto it = s.begin() ; it != s.end() ; ++it){
        res.push_back(*it);
    }
    
    return res;
}
