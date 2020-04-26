/**
 * This problem can be solved by starting from the end of the
 * array. Suppose last_pos is the last index of the array, then we
 * check whether through last_pos-1 we can arrive at last_pos by using
 * the equation nums[last_pos-1]+last_pos-1 >= last_pos. If it is
 * true, last_pos = last_pos-1. In the end we check whether last_pos
 * == 0 is true. If true, then it means we can start from the 0th
 * index to the end of the array.
 */



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_pos = nums.size()-1;
        for (int i = nums.size()-2; i >=0 ; i--) {
            if (nums[i]+i >= last_pos) {
                last_pos = i;
            }
        }
        return last_pos == 0;

    }
};
