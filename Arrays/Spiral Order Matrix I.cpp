vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size(), top = 0, bottom = m-1, left = 0, right = n-1, dir = 0;
    vector<int> res;
    
    while(top <= bottom && left <= right){
        if(dir == 0){
            for(int i = left ; i <= right ; i++){
                res.push_back(A[top][i]);
            }
            top++;
            dir = 1;
        }
        else if(dir == 1){
            for(int i = top ; i <= bottom ; i++){
                res.push_back(A[i][right]);
            }
            right--;
            dir = 2;
        }
        else if(dir == 2){
            for(int i = right ; i >= left ; i--){
                res.push_back(A[bottom][i]);
            }
            bottom--;
            dir = 3;
        }
        else if(dir == 3){
            for(int i = bottom ; i >= top ; i--){
                res.push_back(A[i][left]);
            }
            left++;
            dir = 0;
        }
    }
    
    return res;
}
