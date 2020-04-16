/*xs*
 * I believe this is a hard problem rather than easy. This can be
 * solved by using DP. suppose f is the function of the minimum number
 * of subsequences. thus f(target) = f(substring)+1; the above is only
 * true when f(substring) is a valid value and target-substring which
 * another part of the target is a subsequence of source.
 */



class Solution {
public:
    int shortestWay(string source, string target) {
        int n = target.size();
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i-1; j >=0; --j) {
                if (dp[j] != n+1 and isSub(target.substr(j, i-j), source)) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
                else {break;}
            }
        }
        return dp.back() == n+1?-1:dp.back();

    }

private:
    bool isSub(string t, string s) {
        int i = 0, j = 0;
        int ts = t.size(), ss = s.size();
        while (i < ts and j < ss) {
            if (t[i] == s[j]) {i++; j++;}
            else {j++;}
        }
        return i==ts;
    }
};
