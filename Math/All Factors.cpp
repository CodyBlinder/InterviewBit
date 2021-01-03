vector<int> Solution::allFactors(int A) {
    vector<int> factors;
    
    for(int i=sqrt(A);i>0;i--){
        if(i==sqrt(A)){
            factors.push_back(i);
            continue;
        }
        
        if(A%i==0){
            factors.insert(factors.begin(),i);
            factors.push_back(A/i);
        }
    }
    
    return factors;
}
