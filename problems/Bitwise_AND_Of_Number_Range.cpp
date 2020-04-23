/**
 * This is a tricky problem and I cannot make it in the interview if
 * TLE is not allowed. The solution utilize that n & (n-1) will turn
 * off the right most bit that is not clear. Then n is the common fix
 * between n and m.
 */



class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            n = n&(n-1);
        }
        return n;

    }
};
