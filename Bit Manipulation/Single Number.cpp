#include <numeric>

int Solution::singleNumber(const vector<int> &A) {
    return (A.size()==1)?A[0]:accumulate(A.begin(),A.end(),0,bit_xor<int>());
}
