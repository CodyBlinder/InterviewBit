int Solution::lengthOfLongestSubstring(string A) {
    int n = A.size(), start = 0, res = 0;
    unordered_map<char, int> m;
    
    for(int i = 0 ; i < n ; i++){
        if(m.find(A[i]) != m.end()){
            start = max(start, m[A[i]]+1);
        }
        m[A[i]] = i;
        res = max(res, i-start+1);
    }
    
    return res;
}
