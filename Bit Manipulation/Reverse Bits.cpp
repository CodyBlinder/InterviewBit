unsigned int Solution::reverse(unsigned int A) {
    
    unsigned int res = 0;
    
    for(int i=0;i<32;i++){
        
        res = res<<1 | A%2;
        A = A >> 1;
    }
    
    return res;
}
