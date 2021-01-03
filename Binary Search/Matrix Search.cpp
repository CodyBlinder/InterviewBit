int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    
    int m = A.size(); if(m == 0) return 0;
    int n = A[0].size(); if(n == 0) return 0;
    
    int row = 0, col = n-1;
    while(row < m && col >= 0){
        int val = A[row][col];
        if(val == B){
            return 1;
        }
        else if(val > B){
            col--;
        }
        else{
            row++;
        }
    }
    
    return 0;
}
