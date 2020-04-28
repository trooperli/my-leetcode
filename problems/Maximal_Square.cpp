/**
 * This is a DP problem. The key to solve this problem is for every 1
 * found in the original matrix, we update the value of in the dp
 * matrix using dp(i,j) = min(dp(i-1, j), dp(i-1, j-1), dp(i, j-1))+1.
 */



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {return 0;}
        int m = matrix.size(); //row
        int n = matrix[0].size(); //col
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i+1][j+1] = min(dp[i][j+1], min(dp[i][j], dp[i+1][j]))+1;
                    res = max(res, dp[i+1][j+1]);
                }
            }
        }
        return res*res;

    }
};
