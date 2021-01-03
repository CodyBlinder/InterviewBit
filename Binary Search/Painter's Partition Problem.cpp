int reqdPainters(vector<int> &C, long long int x, int B){
    int n = C.size(), cnt = 1;
    long long int sum = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(sum + C[i] > x){
            cnt++;
            sum = (C[i]);
            if((C[i]) > x){
                return INT_MAX;
            }
        }
        else{
            sum += (C[i]);
        }
    }
    
    return cnt;
}

int Solution::paint(int A, int B, vector<int> &C) {
    
    int n = C.size();
    long long int lo = LONG_MAX, hi, sum = 0, i, res;
    
    for(i = 0 ; i < n ; i++){
        lo = min(lo,(long long)(C[i]));
        hi += (long long)(C[i]);
    }
    
    res = hi%10000003;
    
    while(lo < hi){
        long long int mid = lo + (hi-lo)/2;
        if(reqdPainters(C,mid,B) <= A){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    
    return (lo*(long long)B)%10000003;
}
