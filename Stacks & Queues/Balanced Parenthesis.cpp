int Solution::solve(string A) {
    int n = A.size();
    stack<char> s;
    
    for(int i = 0 ; i < n ; i++){
        if(A[i] == '('){
            s.push(A[i]);
        }
        else{
            if(s.empty()) return 0;
            s.pop();
        }
    }
    
    return s.empty() ? 1 : 0;
}
