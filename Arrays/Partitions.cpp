int Solution::solve(int A, vector<int> &B) {
    int sum = 0, i, res = 0, x = 0, y = 0;
    bool flag = false;
    vector<int> pre, suf;
    
    for(int i = 0 ; i < A ; i++){
        sum += B[i];
    }
    if(sum % 3 != 0) return 0;
    sum = sum/3;
    
    for(int i = 0 ; i < A ; i++){
       x += B[i];
       if(x == sum){pre.push_back(i);}
       y += B[A-i-1];
       if(y == sum){suf.push_back(A-i-1);}
    }
    
    for(int i = 0 ; i < pre.size() ; i++){
        for(int j = 0 ; j < suf.size() ; j++){
            x = 0; flag = false;
            for(int k = pre[i]+1 ; k < suf[j] ; k++){
                x += B[k];
                flag = true;
            }
            if(x == sum && flag){
                res++;
            }
        }
    }
    
    return res;
}
