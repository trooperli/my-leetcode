/**
 * This is a tricky problem. We need to formulate 2 hash maps, first
 * one is to count how many times an element appear in the vector
 * nums. The second one is to count the number of subsequences ending
 * at the ith element. cnt represents the first one and tail
 * represents the second one. we always one to add a new element to
 * the previous subsequence if possible as shown in the code under if
 * (tail[nums[i]-1] > 0); if not we we start a new subsequence;
 * otherwise return false. This problem can be extended to how many
 * subsequences are in the vector nums? We can just return
 * tail[nums[nums.size()-1]].
 */



class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, tail;
        for (int i = 0; i < nums.size(); ++i) {
            cnt[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!cnt[nums[i]]) {continue;}
            cnt[nums[i]]--;
            if (tail[nums[i]-1] > 0) {
                tail[nums[i]-1]--;
                tail[nums[i]]++;
            }
            else if (cnt[nums[i]+1] and cnt[nums[i]+2]) {
                cnt[nums[i]+1]--;
                cnt[nums[i]+2]--;
                tail[nums[i]+2]++;
            }
            else return false;
        }
        return true;
    }
};
