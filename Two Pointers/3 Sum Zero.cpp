#include <set>
#include <vector>
#include <iterator>

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    int n = A.size(), i;
    vector<vector<int>> res;
    set<vector<int>> s;
    
    sort(A.begin(), A.end());
    
    for(i = 0 ; i < n ; i++){
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            if(i == j || i == k) continue;
            
            long long int sum = (long long int)A[i] + (long long int)A[j] + (long long int)A[k];
            if(sum == 0){
                s.insert({A[i],A[j],A[k]});
                j++;
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                k--;
            }
        }
    }
    
    auto it = s.begin();
    for(it = s.begin() ; it != s.end() ; ++it){
        res.push_back(*it);
    }
    
    return res;
}
