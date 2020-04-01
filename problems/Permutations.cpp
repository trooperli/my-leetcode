/**
 * This is a backtrace problem using DFS. Please compare the
 * difference between this one an Generate_Parenthesis.cpp. The second
 * swap used in the code is to backtrace to the previous level, which
 * is the test point of this problem.
 */


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        auto sz = nums.size();
        backtrace(res, nums, 0, sz);
        return res;

    }

    void backtrace(vector<vector<int>>& res, vector<int> nums, int start, int max) {
        if (start == max) {res.push_back(nums); return;}
        for (int i = start; i < max; i++) {
            swap(nums[i], nums[start]);
            backtrace(res, nums, start+1, max);
            swap(nums[start], nums[i]); /*!< The swap is to backtrace
                                          to the previous level */
        }
    }
};
