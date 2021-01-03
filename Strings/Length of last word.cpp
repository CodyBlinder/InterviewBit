int Solution::lengthOfLastWord(const string A) {
    
    int n = A.length();
    
    int i = n-1;
    int count = 0;
    
    while(i>=0){
        if(!isalpha(A[i])){
            if(count!=0){
                break;
            }
            else{
                i--;
            }
        }
        else{
            count++;
            i--;
        }
    }
    
    return count;
}
