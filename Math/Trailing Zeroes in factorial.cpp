int Solution::trailingZeroes(int A) {
    
    int i = 1;
    int ans = 0;
    while(floor(A/(pow(5,i))!=0)){
        ans = ans + floor((A/(pow(5,i))));
        i++;
    }
    
    return ans;
}
