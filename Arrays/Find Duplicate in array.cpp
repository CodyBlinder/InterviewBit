int Solution::repeatedNumber(const vector<int> &A) {
    
    // Method 1 : Using Cycle detection
    int slow = A[0];
    int fast = A[A[0]];
    
    while(slow != fast){
        slow = A[slow];
        fast = A[A[fast]];
    }
    
    fast = 0;
    while(slow != fast){
        slow = A[slow];
        fast = A[fast];
    }
    
    if(!slow){
        return -1;
    }
    
    return slow;
    
    
    // Method 2 : Keeping the record of a visited array
    int n = A.size();
    vector<bool> visited(n+1,false);
    
    int i;
    for(i = 0; i <= n; i++){
        
        if(visited[A[i]]){
            return A[i];
        }
        
        visited[A[i]] = true;
        
    }
    
    return -1;
}
