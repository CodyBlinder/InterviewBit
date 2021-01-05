string Solution::minWindow(string A, string B) {
    int l1 = A.size(), l2 = B.size(), start = 0, cnt = 0, start_index = -1, res = INT_MAX;
    unordered_map<char, int> mA, mB;
    
    if(l1 < l2) return "";
    
    for(int i = 0 ; i < B.size() ; i++){
        mB[B[i]]++;
    }
    
    for(int i = 0 ; i < l1 ; i++){
        mA[A[i]]++;
        if(mB.find(A[i]) != mB.end() && mA[A[i]] <= mB[A[i]]){
            cnt++;
        }
        
        if(cnt == l2){
            // Window is found
            // Try to minimize the window
            while(mB.find(A[start]) == mB.end() || mA[A[start]] > mB[A[start]]){
                if(mA[A[start]] > mB[A[start]]){
                    mA[A[start]]--;
                }
                start++;
            }
            
            // Updating length of window
            if(res > i-start+1){
                res = i-start+1;
                start_index = start;
            }
        }
    }
    
    return start_index==-1 ? "" : A.substr(start_index, res);
}
