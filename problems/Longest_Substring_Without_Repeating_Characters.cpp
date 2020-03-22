/**
 * We used a map to record the location of each character. When there
 * are repeating characters, the start pointer is moved to the same
 * character that appeared last time. For example, character 'a' appears at index
 * 5, if it appears again at index 10, start pointer is set to 5, which means
 * that we only consider the characters after it for a new count,
 * otherwise we would have 2 'a' in the count. In
 * addition, in the map the value fo the character 'a' is updated with the new
 * location.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int start = -1;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(s[i])) {
                start = max(start, mp[s[i]]);
            }
            mp[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};
