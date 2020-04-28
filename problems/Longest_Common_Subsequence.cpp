/**
 * This is a dp problem. We use a DP table to solve this problem,
 * while row is text1, and column is text2. when the character of two
 * string are the same, we set dp(i,j) = dp(i-1, j-1)+1 otherwise we
 * set to the max(dp(i, j-1), dp(i-1, j)).
 */



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (text1[i] == text2[j]) {dp[i+1][j+1] = dp[i][j]+1;}
                else {dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);}
            }
        }
        return dp[m][n];

    }
};
