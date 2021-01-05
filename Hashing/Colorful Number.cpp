int Solution::colorful(int A) {
    string str = to_string(A);
    int n = str.size();
    unordered_set<long long> s;
    long long prod = 1, curr = 1;
    
    for(int i = 0 ; i < n ; i++){
        prod = 1;
        for(int j = i ; j < n ; j++){
            curr = str[j]-'0';
            prod = prod*curr;
            if(s.find(prod) != s.end())
                return 0;
            s.insert(prod);
        }
    }
    
    return 1;
}
