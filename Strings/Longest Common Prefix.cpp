string Solution::longestCommonPrefix(vector<string> &A) {
int min_len = 0, smallest_stridx = INT_MAX, n = A.size();
    for(int i = 0 ; i < n ; i++){
        if(A[i].size() < min_len){
            min_len = A[i].size();
            smallest_stridx = i;
        }
    }
    
    int i = smallest_stridx, cnt = 0, flag = 1;
    
    while(cnt < min_len){
        int j = 0;
        for(j = 0 ; j < n ; j++){
            if(A[j][cnt] != A[i][cnt]){
                flag = 1;
                break;
            }
        }
        
        if(!flag){
            break;
        }
        
        // res = res + A[i][cnt];
        cnt++;
    }
    
    string res = "";
    
    for(int a = 0 ; a < cnt ; a++){
        res = res + A[i][a];
    }
    
    return res;
}
