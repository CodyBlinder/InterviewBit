int isPalindrome(string str, int first, int last){
    
    int flag = 1;
    while(first<=last){
        if(str[first] == str[last]){
            first++;
            last--;
            continue;
        }
        else{
            flag = 0;
            break;
        }
    }
    
    return flag;
}

int Solution::solve(string A) {
    
    int n = A.length();
    
    for(int i=n-1;i>=0;i--){
        if(!isPalindrome(A,0,i)){
            continue;
        }
        else{
            return (n-i-1);
        }
    }
    
    return 0;
}
