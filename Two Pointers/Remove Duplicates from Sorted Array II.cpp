int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size(), ans = 0, flag = 0;
    if(n == 1) return 1;
    
    map<int, int> cnt;
    for(int i = 0 ; i < n ; i++){
        cnt[A[i]]++;
    }
    
    map<int, int>::iterator it;
    for(it = cnt.begin() ; it != cnt.end() ; ++it){
        if(it->second == 1){
            ans++;
        }
        else{
            ans += 2;
        }
    }
    
    int r = 1, w = 1;
    while(w < n && r < n){
        if(A[r] == A[r-1]){
            if(flag == 0){
                flag = 1;
                A[w] = A[r];
                w++;
            }
        }
        else{
            flag = 0;
            A[w] = A[r];
            w++;
        }
        r++;
    }
    
    return ans;
}
