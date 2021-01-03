int Solution::search(const vector<int> &A, int B) {
    
    int low = 0;
    int high = A.size()-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(B==A[mid]){
            return mid;
        }
        
        if(A[mid] <= A[high]){
            if(B>A[mid] && B<=A[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        else{
            if(B>=A[low] && B<A[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    }
    
    return -1;
}
