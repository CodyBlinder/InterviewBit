vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    stack<int> s;
    vector<int> res;
    
    for(int i = 0 ; i < n ; i++){
        while(!s.empty() && s.top() >= A[i]){
            s.pop();
        }
        
        if(s.empty()){
            res.push_back(-1);
        }
        else{
            res.push_back(s.top());
        }
        
        s.push(A[i]);
    }
    
    return res;
}
