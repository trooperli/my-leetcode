/**
 *algorithm that operates on arrays: it starts at the left end
 *(element A[1]) and scans through to the right end (element A[n]),
 *keeping track of the maximum sum subvector seen so far. The maximum
 *is initially A[0]. Suppose we've solved the problem for A[1 .. i -
 *1]; how can we extend that to A[1 .. i]? The maximum
 *sum in the first I elements is either the maximum sum in the first i
 *- 1 elements (which we'll call MaxSoFar), or it is that of a
 *subvector that ends in position i (which we'll call MaxEndingHere).
 */



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        int maxSoFar = nums[0];
        int maxCurrent = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxCurrent = max(maxCurrent+nums[i], nums[i]);
            maxSoFar = max(maxSoFar, maxCurrent);
        }
        return maxSoFar;
    }
};
