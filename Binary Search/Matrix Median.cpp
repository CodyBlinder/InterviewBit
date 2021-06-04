int Solution::findMedian(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    int a = INT_MAX, b = INT_MIN, k = (m*n+1)/2, mid;
    
    for(int i = 0 ; i < m ; i++){
        a = min(a,A[i][0]);
        b = max(b,A[i][n-1]);
    }
    
    while(a < b){
        mid = a + (b-a)/2;
        int count = 0;
        for(int i = 0 ; i < m ; i++){
            count += upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        if(count < k){
            a = mid + 1;
        }
        else{
            b = mid;
        }
    }
    
    return a;
}
