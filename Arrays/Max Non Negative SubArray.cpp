vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    long long curr_sum = 0, max_so_far = INT_MIN, len = 0, num_neg = 0;
    long long start = 0, end = 0, temp_start = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(A[i] < 0){
            curr_sum = 0;
            num_neg++;
            temp_start = i+1;
            continue;
        }
        
        curr_sum += A[i];
        
        if(max_so_far < curr_sum){
            max_so_far = curr_sum;
            start = temp_start;
            end = i;
            len = end-start+1;
        }
        else if(max_so_far == curr_sum){
            if(i-temp_start+1 > len){
                start = temp_start;
                end = i;
                len = end-start+1;
            }
            else if(i-temp_start+1 == len){
                int j1 = temp_start, j2 = start;
                while(j1 <= i && j2 <= end && A[j1] == A[j2]){
                    j1++;
                    j2++;
                }
                if(A[j2] < A[j1]){
                    start = temp_start;
                    end = i;
                    len = end-start+1;
                }
            }
            
            max_so_far = curr_sum;
        }
    }
    
    vector<int> res;
    
    if(num_neg == n) return res;
    
    for(int i = start ; i <= end ; i++){
        res.push_back(A[i]);
    }
    
    return res;
}
