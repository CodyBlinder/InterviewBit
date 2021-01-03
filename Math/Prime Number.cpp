vector<int> Solution::sieve(int A) {
    
    vector<bool> prime(A+1,true);           // marking each number till A as a prime
    
    prime[0] = prime[1] = false;            // unmarking 0 and 1 (not prime)
    
    for(int i=2;i<sqrt(A);i++){
        if(prime[i]){
            for(int j=i*i;j<=A;j+=i){       // unmarking all the factors of i
                prime[j] = false;
            }
        }
    }
    
    vector<int> res;
    for(int i=0;i<A;i++){
        if(prime[i]){
            res.push_back(i);
        }
    }
    
    return res;
}
