int isPrime(int n){
    if(n==1){
        return 0;
    }
    
    int upperLimit = (int)(sqrt(n));
    
    for(int i=2;i<=upperLimit;i++){
        if(n%i==0){ return 0; }
    }
    
    return 1;
}

vector<int> Solution::primesum(int A) {
    vector<int> V;
    
    for(int i=2;i<=A/2;i++){
        if(isPrime(i)==1 && isPrime(A-i)==1){
            V.push_back(i);
            V.push_back(A-i);
            return V;
        }
    }
    
    return V;
}
