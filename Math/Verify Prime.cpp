int Solution::isPrime(int A) {
    int ul = (int)sqrt(A);
    for(int i=2;i<=ul;i++){
        if(A%i==0){
            return 0;
        }
    }
    
    return 1;
}
