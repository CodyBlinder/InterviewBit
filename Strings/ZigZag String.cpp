string Solution::convert(string A, int B) {
    int n = A.size();
    
    if(B==1){
        return A;
    }
    
    int dir = 0; // down direction
    int row = 0; // row number
    
    vector<string> rows(B,"");
    for(int i=0;i<n;i++){
        
        rows[row].push_back(A[i]);
        if(row==0){
            dir = 0;
        }
        if(row==B-1){
            dir = 1;
        }
        
        (dir) ? row-- : row++ ;
    }
    
    string res = "";
    for(int i=0;i<B;i++){
        res += rows[i];
    }
    
    return res;
}
