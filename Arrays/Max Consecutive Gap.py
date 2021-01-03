class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maximumGap(self, A):
        if(len(A) < 2):
            return 0;
        
        A = sorted(A);
        res = A[1]-A[0];
        
        for i in range(1, len(A)-1):
            res = max(res, A[i+1]-A[i]);
            
        return res;
