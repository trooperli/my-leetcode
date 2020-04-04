/**
 * This is a easy problem. We create 2 pointers, a fast and a slow
 * one. Fast one basically loop through the vector. Slow one only
 * increase when the element pointed by the fast is non zero. In this
 * case, we first swap the two element between the fast and slow
 * pointers, then increase the slow pointer by 1.
 */


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        for (fast = 0; fast < nums.size(); ++fast)
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
    }
};
