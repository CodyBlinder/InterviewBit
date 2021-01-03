vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    
    vector<int> v;
    for(int i = 0 ; i < n ; i++){
        v.push_back(A[i]);
    }
    
    // Transform the array into arr[i] = i+1
    for(int i = 0 ; i < n ; i++){
        while(v[v[i]-1] != v[i]){
            swap(v[v[i]-1], v[i]);
        }
    }
    
    // Position at which arr[i]!=i+1 gives the missing number and the repeated number
    vector<int> res;
    for(int i = 0 ; i < n ; i++){
        if(v[i] != i+1){
            res.push_back(v[i]);
            res.push_back(i+1);
        }
    }
    
    return res;
}
