/**
 * This problem is solved by using 2 pointers. The key is to find how
 * the pointers move. Initially, one is at the begin, the other is at
 * the end. When the value of the left pointer points is smaller than
 * the right pointer, left pointer++; otherwise right pointer--. The
 * end condition is left < right. This problem can also be solved by
 * using brute force, but it will TLE in one test case.
 */



class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res = (right-left)*min(height[left], height[right]);
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
            }
            else {right--;}
            auto tmp = (right-left)*min(height[left], height[right]);
            if (tmp > res) {res = tmp;}
        }
        return res;


    }
};
