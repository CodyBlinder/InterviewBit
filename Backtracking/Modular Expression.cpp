long long int MOD(int A,int B,int C){
    if(B==0){
        return 1;
    }
    else if(B%2==0){
        long long int y = MOD(A,B/2,C);
        return (y*y)%C;
    }
    else{
        return (A%C * MOD(A,B-1,C))%C;
    }
}

int Solution::Mod(int A, int B, int C) {
    if(A==0){
        return 0;
    }
    
    long long int ans = MOD(A,B,C);
    if(ans<0){
        return ans + C;
    }
    else{
        return ans;
    }
}
