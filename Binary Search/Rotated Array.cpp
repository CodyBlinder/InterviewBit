int Solution::findMin(const vector<int> &A) {
    
    int low = 0;
    int high = A.size()-1;
    
    while(low < high){
        int mid = low + (high-low)/2;
        
        if(A[mid] <= A[high]){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    
    return A[low];
}
