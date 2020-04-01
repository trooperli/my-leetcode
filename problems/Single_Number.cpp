/**
 * This is a bitwise operation. The XOR of two identical number is 0,
 * and the XOR of 0 and a is a.
 */


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (const auto &elem : nums) {
            a = a ^ elem;
        }
        return a;

    }
};
