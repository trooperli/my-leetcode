/**
 * This problem seems easy but not if it requires O(n) time complexity
 * and O(1) space complexity. The key to this problem is when nums[i]
 * != i, we do a swap(nums[i], nums[nums[i]]). Suppose nums[0] = 3,
 * nums[3] = 4,after this swap, we have nums[3] = 3 and nums[0] = 4;
 * then we swap(nums[0], nums[4]), suppose nums[4] = 0,we have nums[4]
 * = 4 and nums[0]=0, and we move on to the next element in the array.
 */



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return 0;
    }
};
