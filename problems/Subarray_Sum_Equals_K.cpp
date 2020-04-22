/**
 * If the cumulative sum upto two indeces is the same, the sum of the
 * elmenets lying in between those indices is zero. If the cumulative
 * sum up to two indeces, say i and j is at a difference of k, the sum
 * of elements lying between indices i and j is k. Suppose mp[j] = 1,
 * but mp[j-k] = 2, then we have two sub arrays that sums equal to
 * k.
 */



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] =1;
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = sum+nums[i];
            if (mp.count(sum-k)) {res += mp[sum-k];}
            mp[sum]++;

        }
        return res;
    }
};
