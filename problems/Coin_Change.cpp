/**
 * This is a typical bag/DP problem. Let's say function f() represents
 * the number of coins, thus min(f[amount]) = min(f[amount-c1],
 * f[amount-c2], f[amount-c3])+1, where c1, c2, and c3 are three
 * different coins. This idea is carried by the code in code dp[i] =
 * min(dp[i],dp[i-coin]+1). Because coin is a variable in the code,
 * basically this line is find the min(f[amount-c1],
 * f[amount-c2], f[amount-c3])+1. In the initialization, we create an
 * array to store the minimum number of coins for each amount. The
 * initial value in each element is amount+1 which is impossibile
 * considering the maximum number of coins for amount is amount if we
 * only allowed to use coin 1.
 * This is a bottom up problem. For example, suppose amount is 6,
 * c1 is 1, c2 is 2, c3 is 3; in order to calculate min(f[6]), we need
 * to know min(f[6-1], f[6-2], f[6-3]), which means we need to know
 * f[3], f[4], and f[5] first. That's why it is called bottom up.
 */



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int coin:coins) {
            for (int i = coin; i < amount+1; ++i) {
                dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
        return dp[amount] == amount+1 ? -1:dp[amount];

    }
};
