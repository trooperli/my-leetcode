/**
 * This is a binary search problem. Unlike search in the sorted
 *  array, this array is a rotated soredt array. To solve this kind of
 *  problem, we need to check whether the pivot is on the right side
 *  or the left side of the mid element and this is the key to solve
 *  this problem. To do this we need to compare the mid value with the
 *  start value if (nums[mid] >= nums[start]).
 */


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while (start <= end) {
            int mid = start+(end-start)/2;
            if (nums[mid] == target) {return mid;}
            if (nums[mid] >= nums[start]) {
                if (target >= nums[start] and target < nums[mid]) {
                    end = mid-1;
                }
                else {start = mid+1;}
            }
            else {
                if (target > nums[mid] and target <= nums[end]) {
                    start = mid+1;
                }
                else {end = mid-1;}
            }
        }
        return -1;

    }
};
