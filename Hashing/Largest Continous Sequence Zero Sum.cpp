vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size(), curr_sum = 0, start = 0, end = 0, curr_len = 0, max_len = 0;
    unordered_map<int, int> m;
    
    m[0] = -1;
    
    // Hash Table
    // Key -> current prefix sum
    // Value -> ending index of subarray with current sum, which will act as start idx later
    for(int i = 0 ; i < n ; i++){
        curr_sum += A[i];
        if(m.find(curr_sum) != m.end()){
            curr_len = i-m[curr_sum];
            if(curr_len > max_len){
                max_len = curr_len;
                start = m[curr_sum]+1;
                end = i;
            }
            // Here we will not insert curr_i in map as we want idx for curr_sum to be min
        }
        else{
            m[curr_sum] = i;
        }
    }
    
    vector<int> res;
    if(start == end && A[start] != 0) return res;
    for(int i = start ; i <= end ; i++){
        res.push_back(A[i]);
    }
    
    return res;
}
