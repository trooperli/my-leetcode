/**
 * This problem can be solved by hash table. The key is the sorted
 * string and the value is a vector of the key's variations.
 */





class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) {return res;}
        vector<string> strs_cp = strs;
        for (int i = 0; i < strs.size(); ++i) {
            sort(strs[i].begin(), strs[i].end());
        }
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); ++i) {
            if (map.count(strs[i])) {map[strs[i]].push_back(strs_cp[i]);}
            else {vector<string> tmp {strs_cp[i]};
                map[strs[i]] = tmp;}
        }

        for (auto it = map.begin(); it != map.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};
