/**
 * This problem can be solved by using priority queue with the
 * smaller value in the front. To find the kth largest value in the
 * array, we only need to maitain the queue of size k, with the top
 * element the value we need to find. When the queue size is larger
 * than k, we pop the first element.
 */




class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,std::vector<int>, std::greater<int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
            if (q.size() > k) {q.pop();}
        }
        return q.top();

    }
};
