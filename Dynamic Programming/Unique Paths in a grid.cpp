int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> dp){
    int m = grid.size(), n = grid[0].size();
    
    if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1){return 0;}
    
    if(i == m-1 && j == n-1){
        return 1;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int a = solve(grid, i+1, j, dp);
    int b = solve(grid, i, j+1, dp);
    
    return dp[i][j] = a + b;
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size(), res = 0;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(A, 0, 0, dp);
}
