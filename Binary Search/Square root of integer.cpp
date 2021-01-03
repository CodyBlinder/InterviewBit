int Solution::sqrt(int A) {
    
    long int low = 1;
    long int high = A;
    long int res = 0;
    
    while(low <= high){
        long int mid = low + (high-low)/2;
        
        if(mid*mid == A){
            return mid;
        }
        else if(mid*mid < A){
            res = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    return res;
}
