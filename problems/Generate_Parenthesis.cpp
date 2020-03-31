/**
 * A typical DFS problem using recursion. For detailed explanation
 * see https://www.cnblogs.com/grandyang/p/4444160.html
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string initial_str = "";
        backtrack(res, initial_str, 0, 0, n);
        return res;

    }

    void backtrack(vector<string> &res, string curr, int open, int close, int max) {
        if (curr.size() == max*2) {
            res.push_back(curr);
            return;
        }

        if (open < max) {
            backtrack(res, curr+"(", open+1, close, max);
        }
        if (close < open) {
            backtrack(res, curr+")", open, close+1, max);
        }
    }
};
