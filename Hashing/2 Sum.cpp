vector<int> Solution::twoSum(const vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> m;
    vector<int> v{INT_MAX, INT_MAX};
    
    for(int i = 0 ; i < n ; i++){
        if(m.find(B-A[i]) != m.end()){
            if(i < v[1]){
                v[0] = m[B-A[i]];
                v[1] = i;
            }
            else if(i == v[1]){
                v[0] = min(v[0], m[B-A[i]]);
            }
        }
        if(m.find(A[i]) == m.end()){
            m[A[i]] = i;
        }
    }
    
    if(v[0]==INT_MAX && v[1]==INT_MAX) return {};
    
    v[0] = v[0] + 1;
    v[1] = v[1] + 1;
    
    return v;
}
