int Solution::threeSumClosest(vector<int> &A, int B) {
    int n = A.size(), i, j, k;
    long long int res = 1000000000, sum = 0;
    
    sort(A.begin(), A.end());
    
    for(i = 0 ; i < n ; i++){
        j = i + 1;
        k = n - 1;
        while(j < k){
            sum = (long long int)A[i] + A[j] + A[k];
            if(abs(B-sum) < abs(B-res)){
                res = sum;
            }
            else if(sum > B){
                k--;
            }
            else{
                j++;
            }
        }
    }
    
    return res;
}
