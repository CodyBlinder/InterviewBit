int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size(), max_area = 0, curr_area = 0;
    stack<int> s;
    vector<int> left(n), right(n);
    
    // NSE to the left
    for(int i = 0 ; i < n ; i++){
        while(!s.empty() && A[s.top()] >= A[i]){
            s.pop();
        }
        
        if(s.empty()){
            left[i] = -1;
        }
        else{
            left[i] = s.top();
        }
            
        s.push(i);
    }
    
    // Clearing the stack to reuse
    while(!s.empty()){
        s.pop();
    }
    
    // NSE to the right
    for(int i = n-1 ; i >= 0 ; i--){
        while(!s.empty() && A[s.top()] >= A[i]){
            s.pop();
        }
        
        if(s.empty()){
            right[i] = n;
        }
        else{
            right[i] = s.top();
        }
        
        s.push(i);
    }
    
    // Calculate the areas
    for(int i = 0 ; i < n ; i++){
        curr_area = (right[i]-left[i]-1)*(A[i]);
        max_area = max(max_area, curr_area);
    }
    
    return max_area;
}
