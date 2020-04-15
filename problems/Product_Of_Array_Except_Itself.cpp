/**
 * This problem seems to be easy but not if division is not
 * allowed. The solution is to construct two arrays L[i] and R[i],
 * while L[i] is the production of all elements on the left side of
 * nums[i], and R[i] is the production of all elemens on the right side
 * of nums[i].
 */



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> L = nums;
        vector<int> R = nums;
        L[0] = 1;
        R[nums.size()-1] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            L[i] = L[i-1]*nums[i-1];
        }
        for (int i = nums.size()-1; i >= 1; --i) {
            R[i-1] = R[i]*nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = L[i]*R[i];
        }
        return nums;
    }
};
