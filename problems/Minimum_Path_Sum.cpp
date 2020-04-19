/**
 * First I think of using greedy but obviously it won't work. Then the
 * only choice we have is to use DP. Considering the path can only be
 * right or down, thus we have f(m,n) = min(f(m-1,n), f(m,
 * n-1))+grid[m-1][n-1]. We need to be really careful about the edge
 * condition, which is the first row and column in the dp matrix. See
 * the condition clause in the code.
 */



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {return 0;}
        int m = grid.size(); //row
        int n = grid[0].size(); //col
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i==1 and j == 1) {dp[i][j] = grid[i-1][j-1];}
                else if (i == 1) {dp[i][j] = dp[i][j-1]+grid[i-1][j-1];}
                else if (j == 1) {dp[i][j] = dp[i-1][j]+grid[i-1][j-1];}
                else {dp[i][j] = min(dp[i][j-1], dp[i-1][j])+grid[i-1][j-1];}
            }
        }
        return dp[m][n];

    }
};
