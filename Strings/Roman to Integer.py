class Solution:
    # @param A : string
    # @return an integer
    def romanToInt(self, A):
        values = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        n = len(A)
        res = 0
        for x in range(0,n-1,1):
            if(values[A[x]] >= values[A[x+1]]):
                res = res + values[A[x]]
            else:
                res = res - values[A[x]]
       
        res = res + values[A[n-1]]
        
        return res
