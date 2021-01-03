int Solution::reverse(int A) {
    
    int B = abs(A);
    
    string rev = "";
    
    while(B!=0){
        rev = rev + (to_string)(B%10);
        B = B/10;
    }
    
    int res;
    
    try{
        res = stoi(rev);
    }
    catch(std::out_of_range){
        return 0;
    }
    
    if(A<0){
        res = res * -1;
    }
    
    if(abs(res) > INT_MAX){
        return 0;
    }
    
    return res;
}
