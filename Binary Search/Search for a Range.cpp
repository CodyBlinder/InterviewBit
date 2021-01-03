int search(vector<int> V, int target, bool search_first){
    
    int low = 0;
    int high = V.size()-1;
    int res = -1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(target==V[mid]){
            res = mid;
            if(search_first){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else if(target > V[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    return res;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    int first = search(A,B,true);
    int last = search(A,B,false);
    
    vector<int> ans;
    ans.push_back(first);
    ans.push_back(last);
    
    return ans;
}
