/**
 * This problem can be solved by DP. max(f(n)) = max(f(n-1), f(n)). In
 * this case f(n) is max_current and f(n-1) is max_soFar. This problem
 * is very similiar to maximum subarray.
 */



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_current = 0;
        int max_soFar = 0;
        for (int i = 1; i < prices.size(); ++i) {
            max_current = max(max_current+prices[i]-prices[i-1], 0);
            max_soFar = max(max_current, max_soFar);
        }
        return max_soFar;
    }
};
