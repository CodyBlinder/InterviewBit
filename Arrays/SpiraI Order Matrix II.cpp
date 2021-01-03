vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> res(A,vector<int> (A,0));
    int k=1;
    
    int top=0, bottom=A-1, left=0, right=A-1;
    int dir=0;
    
    while(top<=bottom && left<=right){
        if(dir==0){
            for(int i=left;i<=right;i++){
                res[top][i]=k++;
            }
            top++;
            dir=1;
        }
        else if(dir==1){
            for(int i=top;i<=bottom;i++){
                res[i][right]=k++;
            }
            right--;
            dir=2;
        }
        else if(dir==2){
            for(int i=right;i>=left;i--){
                res[bottom][i]=k++;
            }
            bottom--;
            dir=3;
        }
        else if(dir==3){
            for(int i=bottom;i>=top;i--){
                res[i][left]=k++;
            }
            left++;
            dir=0;
        }
    }
    
    return res;
}
