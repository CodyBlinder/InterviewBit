vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size(), carry = 1;
    vector<int> res;
    
    for(int i = n-1 ; i >= 0 ; i--){
        res.push_back((A[i]+carry)%10);
        carry = (A[i]+carry)/10;
    }
    
    if(carry){res.push_back(carry);}
    
    int x = res.size();
    for(int i = 0 ; i < x/2 ; i++){
        swap(res[i], res[x-1-i]);
    }
    
    while(res[0] == 0){res.erase(res.begin());}
    
    return res;
}
