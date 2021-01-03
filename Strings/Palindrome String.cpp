int Solution::isPalindrome(string A) {
    
    for(int i=0;i<A.length();i++){
        if(A[i]>='A' && A[i]<='Z'){
            A[i] = A[i] + 32;
        }
    }
    
    int first = 0;
    int last = A.length()-1;
    
    while(first<last){
        
        if(!isalnum(A[first])){
            first++;
            continue;
        }
        
        if(!isalnum(A[last])){
            last--;
            continue;
        }
        
        if(A[first] == A[last]){
            first++;
            last--;
            continue;
        }
        else{
            return 0;
        }
    }
    
    return 1;
}
