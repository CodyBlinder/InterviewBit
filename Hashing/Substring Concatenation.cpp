vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int n = A.size(), k = B[0].size();
    vector<int> res;
    if(B.size() == 0 || n == 0) return res;
    multiset<string> words;
    
    for(auto s : B){
        words.insert(s);
    }
    
    for(int i = 0 ; i < n ; i++){
        multiset<string> curr;
        for(int j = i ; j < i+B.size()*k ; j+=k){
            if(j >= n) break;
            curr.insert(A.substr(j, k));
        }
        if(curr == words) res.push_back(i);
    }
    
    return res;
}
