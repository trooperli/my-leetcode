/**
 * Use the Floyd cycle detection algorithm. We have two pointers, a
 * fast and slow. Eventually fast will be equal to slow. If
 * fast=slow=1,return true, otherwise, return false.
 */



class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {slow = calSum(slow);
            fast = calSum(fast);
            fast = calSum(fast);
            if (fast == 1) {return true;}} while(fast != slow);
        return false;

    }

    int calSum(int n) {
        int sum = 0;
        while (n) {
            auto digit = n % 10;
            sum += pow(digit, 2);
            n = n /10;
        }
        return sum;
    }
};
