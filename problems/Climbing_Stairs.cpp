/**
 * This is a dp problem. suppose f(n) represents the ways of climbing
 * to the nth floor. In dp problem, it can be divide into sub
 * problems, as f(n) = f(n-1)+f(n-2).
 */



class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n+1, n+1);
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i < res.size(); ++i) {
            res[i] = res[i-1]+res[i-2];
        }
        return res[n];

    }
};
