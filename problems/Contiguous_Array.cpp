/**
 * We make use of a count variable, which is used to store the
 * relative number of ones and zeros encountered so far while
 * traversing the array. The count variable is incremented by one for
 * every 1 encountered and the same is decremented by one for every 0
 * encountered. Then we use unordered_map to store the start and stop
 * index for each counter. In the end we return the
 * max(stop_index-start_index).
 */



class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ct = 0;
        unordered_map<int, vector<int>> mp;
        mp[0].emplace_back(0);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)  {ct--;}
            else if (nums[i] == 1) {ct++;}
            if (mp.count(ct)) {
                mp[ct].emplace_back(i+1);
                int sz = mp[ct].size();
                int tmp = mp[ct][sz-1]-mp[ct][0];
                if (tmp > res) {res = tmp;}
            }
            else {mp[ct].emplace_back(i+1);}
        }
        return res;


    }
};
