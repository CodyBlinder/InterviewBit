int Solution::titleToNumber(string A) {
    int n = A.length();

    int res = 0;
    
    for(int i=0;i<n;i++){
        res = res + ((int)(A[i]-64)*pow(26,n-i-1));
    }
    
    return res;
}
