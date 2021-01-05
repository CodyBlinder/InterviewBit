int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size(), dy, dx, g, dups, curr_max, res = 0;
    
    for(int i = 0 ; i < n ; i++){
        unordered_map<string, int> m;
        string slope;
        dups = 1;
        curr_max = 0;
        for(int j = i+1 ; j < n ; j++){
            dy = B[j]-B[i];
            dx = A[j]-A[i];
            if(dy == 0 && dx == 0){
                dups++;
                continue;
            }
            if(dx != 0){
                g = __gcd(dx, dy);
                dy /= g;
                dx /= g;
            }
            if(dx == 0){
                dy = 1;
            }
            slope = to_string(dy) + '/' + to_string(dx);
            m[slope]++;
            curr_max = max(curr_max, m[slope]);
        }
        curr_max += dups;
        res = max(res, curr_max);
    }
    
    return res;
}
