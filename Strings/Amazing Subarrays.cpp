int isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        return 1;
    }
    else{
        return 0;
    }
}

int Solution::solve(string A) {
    
    int count = 0;
    
    for(int i=0;i<A.length();i++){
        if(isVowel(A[i])){
            count = count + (A.length()-i);
        }
    }
    
    return (count % 10003);
}
